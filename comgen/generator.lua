
local cosmo = require "cosmo"

local _M = {}

local template = cosmo.compile(require("comgen.template"))
local template_def = cosmo.compile[[
EXPORTS
    luaopen_$modname
]]
local template_wrapper = cosmo.compile(require("comgen.template_wrapper"))

local template_set_enum = cosmo.compile[[
  lua_getfield(L, LUA_REGISTRYINDEX, "luacomgen_enums");
  lua_getfield(L, -1, "$(type.typedef)");
  lua_pushvalue(L, $stkidx);
  lua_gettable(L, -2);
  $var = ($(type.typedef))lua_tointeger(L, -1);
  lua_pop(L, 3);
]]

local template_push_enum = cosmo.compile[[
  lua_getfield(L, LUA_REGISTRYINDEX, "luacomgen_enums");
  lua_getfield(L, -1, "$(type.typedef)");
  lua_pushinteger(L, (int)$var);
  lua_gettable(L, -2);
  lua_remove(L, -2);
  lua_remove(L, -2);
]]

local template_init_struct = cosmo.compile[=[
  $fields[[
    $if{init}[[$init{ "("..var..")."..name, type, type.attributes }]]
  ]]
]=]

local template_set_struct = cosmo.compile[=[
  { int __pos_$(strip(stkidx));
  $fields[[
    $if{set}[[
      lua_getfield(L, $stkidx, "$name");
      __pos_$(strip(stkidx)) = lua_gettop(L);
      $set{ "(" .. var..")."..name, "__pos_" .. strip(stkidx), type, type.attributes }
      lua_pop(L, 1);
    ]]
  ]] }
]=]

local template_push_struct = cosmo.compile[=[
  lua_newtable(L);
  $fields[[
    $if{push}[[$push{ "(" .. var..")."..name, type, type.attributes }
          lua_setfield(L, -2, "$name");]]
  ]]
]=]

local template_clear_struct = cosmo.compile[=[
  $fields[[
    $if{clear}[[$clear{ "(" .. var..")."..name, type, type.attributes }]]
  ]]
]=]

local template_set_array = cosmo.compile[=[
  $if{set}[[
    { int __pos_$(strip(stkidx));
    if(lua_objlen(L, $stkidx) != $size)
      luaL_error(L, "array size does not match, expected: %i, actual: %i", $size, lua_objlen(L, $stkidx));
    $var = ($ctype *)CoTaskMemAlloc($size * sizeof($ctype));
    for(size_t $idx = 0; $idx < $size; $idx++) {
      lua_rawgeti(L, $stkidx, $idx + 1);
      __pos_$(strip(stkidx)) = lua_gettop(L);
      $if{init}[[$init{ var .. "[" .. idx .. "]", type, type.attributes }]]
      $set{ var .. "[" .. idx .. "]", "__pos_" .. strip(stkidx), type, type.attributes }
      lua_pop(L, 1);
    } }
  ]]
]=]

local template_push_array = cosmo.compile[=[
  lua_newtable(L);
  $if{push}[[
    for(size_t $idx = 0; $idx < $size; $idx++) {
      $push{ var.."[" .. idx .. "]", type, type.attributes }
      lua_rawseti(L, -2, $idx + 1);
    }
  ]]
]=]

local template_clear_array = cosmo.compile[=[
  $if{clear}[[
    for(size_t $idx = 0; $idx < $size; $idx++) {
      $clear{ var.. "[" .. idx .. "]", type, type.attributes }
    }
  ]]
  CoTaskMemFree($var);
]=]

local template_set_safearray = cosmo.compile[=[
  size_t __$(name)_n = lua_objlen(L, $stkidx);
  $name = SafeArrayCreateVector(comgen_name2vt(L, "$(elem.vt)"), $lbound, __$(name)_n);
  if(!$name) luaL_error(L, "could not create SAFEARRAY $name");
  $(elem.ctype) * __$(name)_elems;
  __hr = SafeArrayAccessData($name, (void**)&__$(name)_elems);
  if(!SUCCEEDED(__hr)) luaL_error(L, "could not access SAFEARRAY $name");
  for(long i = $lbound, j = 1; j <= __$(name)_n; i++, j++) {
    $if{elem.init}[[$(elem.init){ "__" .. name .. "_elems[i]" , elem.type, elem.type.attributes }]]
    lua_pushinteger(L, j);
    lua_gettable(L, $stkidx);
    $(elem.set){ "__" .. name .. "_elems[i]", -1, elem.type, elem.type.attributes }
    lua_pop(L, 1);
  }
  SafeArrayUnaccessData($name);
]=]

local template_push_safearray = cosmo.compile[=[
  if(SafeArrayGetDim($name) != 1) luaL_error(L, "SAFEARRAY $name is not a vector");
  $(elem.ctype) * __$(name)_elems;
  __hr = SafeArrayAccessData($name, (void**)&__$(name)_elems);
  if(!SUCCEEDED(__hr)) luaL_error(L, "could not access SAFEARRAY $name");
  long lbound, ubound;
  SafeArrayGetUBound($name, 1, &ubound);
  SafeArrayGetLBound($name, 1, &lbound);
  lua_newtable(L);
  for(long i = lbound, j = 1; i<= ubound; i++, j++) {
    lua_pushinteger(L, j);
    $(elem.push){ "__" .. name .. "_elems[i]", elem.type, elem.type.attributes }
    lua_settable(L, -3);
  }
  SafeArrayUnaccessData($name);
]=]

local template_set_refiid = cosmo.compile[=[
  size_t __$(strip(var))_size;
  const char *__$(strip(var))_siid = lua_tolstring(L, $stkidx, &__$(strip(var))_size);
  if(__$(strip(var))_size >= GUID_SIZE) {
    luaL_error(L, "invalid IID: too long!");
  }
  wchar_t __$(strip(var))_wsiid[GUID_SIZE];
  mbstowcs(__$(strip(var))_wsiid, __$(strip(var))_siid, GUID_SIZE);
  __hr = IIDFromString(__$(strip(var))_wsiid, &$var);
  if(!SUCCEEDED(__hr)) comgen_error(L, __hr);
]=]

local template_push_refiid = cosmo.compile[=[
  char __$(strip(var))_p_siid[GUID_SIZE];
  wchar_t __$(strip(var))_p_wsiid[GUID_SIZE];
  __hr = StringFromIID($var, (LPOLESTR *)__$(strip(var))_p_wsiid);
  if(!SUCCEEDED(__hr)) comgen_error(L, __hr);
  wcstombs(__$(strip(var))_p_siid, __$(strip(var))_p_wsiid, GUID_SIZE);
  lua_pushlstring(L, __$(strip(var))_p_siid, GUID_SIZE);
]=]

local counter
do
  local count = 0
  counter = function ()
              count = count + 1
              return count
            end
end

local comtypes
comtypes = {
  bool = {
    vt = "INT",
    ctype = function (type)
              return "BOOL"
            end,
    set = function (args)
            return args[1] .. " = lua_toboolean(L, " .. args[2] .. ");"
          end,
    push = function (args)
             return "lua_pushboolean(L, " .. args[1] .. ");"
           end,
  },
  int = {
    vt = "INT",
    ctype = function (type)
              return type.name
            end,
    set = function (args)
            return args[1] .. " = lua_tointeger(L, " .. args[2] .. ");"
          end,
    push = function (args)
             return "lua_pushinteger(L, " .. args[1] .. ");"
           end,
  },
  char = {
    vt = "I1",
    ctype = function (type)
              return type.name
            end,
    set = function (args)
            return args[1] .. " = (char)lua_tointeger(L, " .. args[2] .. ");"
          end,
    push = function (args)
             return "lua_pushinteger(L, " .. args[1] .. ");"
           end,
  },
  ["unsigned char"] = {
    vt = "UI1",
    ctype = function (type)
              return type.name
            end,
    set = function (args)
            return args[1] .. " = (unsigned char)lua_tointeger(L, " .. args[2] .. ");"
          end,
    push = function (args)
             return "lua_pushinteger(L, " .. args[1] .. ");"
           end,
  },
  short = {
    vt = "I2",
    ctype = function (type)
              return type.name
            end,
    set = function (args)
            return args[1] .. " = (short)lua_tointeger(L, " .. args[2] .. ");"
          end,
    push = function (args)
             return "lua_pushinteger(L, " .. args[1] .. ");"
           end,
  },
  ["unsigned short"] = {
    vt = "UI2",
    ctype = function (type)
              return type.name
            end,
    set = function (args)
            return args[1] .. " = (unsigned short)lua_tointeger(L, " .. args[2] .. ");"
          end,
    push = function (args)
             return "lua_pushinteger(L, " .. args[1] .. ");"
           end,
  },
  long = {
    vt = "I4",
    ctype = function (type)
              return type.name
            end,
    set = function (args)
            return args[1] .. " = lua_tointeger(L, " .. args[2] .. ");"
          end,
    push = function (args)
             return "lua_pushinteger(L, " .. args[1] .. ");"
           end,
  },
  ["unsigned long"] = {
    vt = "UI4",
    ctype = function (type)
              return type.name
            end,
    set = function (args)
            return args[1] .. " = (unsigned long)lua_tointeger(L, " .. args[2] .. ");"
          end,
    push = function (args)
             return "lua_pushnumber(L, (double)" .. args[1] .. ");"
           end,
  },
  float = {
    vt = "R4",
    ctype = function (type)
              return type.name
            end,
    set = function (args)
            return args[1] .. " = lua_tonumber(L, " .. args[2] .. ");"
          end,
    push = function (args)
             return "lua_pushnumber(L, " .. args[1] .. ");"
           end,
  },
  double = {
    vt = "R8",
    ctype = function (type)
              return type.name
            end,
    set = function (args)
            return args[1] .. " = lua_tonumber(L, " .. args[2] .. ");"
          end,
    push = function (args)
             return "lua_pushnumber(L, " .. args[1] .. ");"
           end,
  },
  enum = {
    ctype = function (type)
              return type.typedef
            end,
    set = function (args)
            return template_set_enum{ type = args[3], stkidx = args[2], var = args[1] }
          end,
    push = function (args)
             return template_push_enum{ type = args[2], var = args[1] }
           end,
  },
  array = {
    ctype = function (type, attr)
              return comtypes[type.elem_type.name].ctype(type.elem_type, attr) .. "*"
            end,
    set = function (args)
            local elem_type = args[3].elem_type
            local struct = args[1]:match("^([^%.]+%.)")
            return template_set_array{ stkidx = args[2], var = args[1], type = elem_type, idx = "__arr_idx_" .. counter(),
                                       set = comtypes[elem_type.name].set, size = (struct or "") .. args[4].size_is,
                                       ctype = comtypes[elem_type.name].ctype(elem_type, args[4]), init = comtypes[elem_type.name].init,
                                       ["if"] = cosmo.cif,
                                       strip = function (s)
                                                 if not tonumber(s) then
                                                   return s:gsub(" ", "_"):gsub("%+", "__"):gsub("%[","__"):gsub("%]","__")
                                                 else
                                                   return s
                                                 end
                                               end }
          end,
    push = function (args)
            local elem_type = args[2].elem_type
            local struct = args[1]:match("^([^%.]+%.)") or ""
            return template_push_array{ var = args[1], type = elem_type, idx = "__arr_idx_" .. counter(),
                                        push = comtypes[elem_type.name].push, size = struct .. args[3].size_is,
                                        ["if"] = cosmo.cif }
           end,
    clear = function (args)
              local elem_type = args[2].elem_type
              local struct = args[1]:match("^([^%.]+%.)") or ""
              return template_clear_array{ var = args[1], type = elem_type, idx = "__arr_idx_" .. counter(),
                                           clear = comtypes[elem_type.name].clear, size = struct .. args[3].size_is,
                                           ["if"] = cosmo.cif }
            end
  },
  struct = {
    ctype = function (type)
              return type.typedef
            end,
    init = function (args)
             local type = args[2]
             local fields = {}
             for _, field in ipairs(type.fields) do
               fields[#fields+1] = { type = field.type, init = comtypes[field.type.name].init, name = field.name }
             end
             return template_init_struct{ fields = fields, var = args[1], ["if"] = cosmo.cif }
           end,
    set = function (args)
            local type = args[3]
            local fields = {}
            for _, field in ipairs(type.fields) do
              fields[#fields+1] = { type = field.type, set = comtypes[field.type.name].set, name = field.name }
            end
            return template_set_struct{ fields = fields, stkidx = args[2], var = args[1], ["if"] = cosmo.cif,
            strip = function (s)
                      if not tonumber(s) then
                        return s:gsub(" ", "_"):gsub("%+", "__"):gsub("%[","__"):gsub("%]","__")
                      else
                        return s
                      end
                    end }
          end,
    push = function (args)
             local type = args[2]
             local fields = {}
             for _, field in ipairs(type.fields) do
               fields[#fields+1] = { type = field.type, push = comtypes[field.type.name].push, name = field.name }
             end
             return template_push_struct{ fields = fields, var = args[1], ["if"] = cosmo.cif }
           end,
    clear = function (args)
              local type = args[2]
              local fields = {}
              for _, field in ipairs(type.fields) do
                fields[#fields+1] = { type = field.type, clear = comtypes[field.type.name].clear, name = field.name }
              end
              return template_clear_struct{ fields = fields, var = args[1], ["if"] = cosmo.cif }
            end
  },
  variant = {
    vt = "VARIANT",
    ctype = function (type)
              return "VARIANT"
            end,
    init = function (args)
             return "VariantInit(&" .. args[1] .. ");"
           end,
    set = function (args)
            return "comgen_set_variant(L, " .. args[2] .. ", &" .. args[1] .. ");"
          end,
    push = function (args)
             return "comgen_push_variant(L, &" .. args[1] .. ");"
           end,
    clear = function (args)
              return "VariantClear(&" .. args[1] .. ");"
            end,
  },
  bstring = {
    vt = "BSTR",
    ctype = function (type)
              return "BSTR"
            end,
    set = function (args)
            return args[1] .. " = comgen_tobstr(L, " .. args[2] .. ");"
          end,
    push = function (args)
             return "comgen_pushbstr(L, " .. args[1] .. ");"
           end,
    clear = function (args)
              return "SysFreeString(" .. args[1] .. ");"
            end,
  },
  tstring = {
    ctype = function (type, attr)
              if attr.ctype then return attr.ctype end
              if attr["in"] and not attr.out and not attr.ref then
                return "LPCTSTR"
              else
                return "LPTSTR"
              end
            end,
    set = function (args)
            return args[1] .. " = comgen_totstr(L, " .. args[2] .. ");"
          end,
    push = function (args)
             return "comgen_pushtstr(L, " .. args[1] .. ");"
           end,
    clear = function (args)
              return "comgen_cleartstr((TCHAR*)" .. args[1] .. ");"
            end,
  },
  wstring = {
    ctype = function (type, attr)
              if attr.ctype then return attr.ctype end
              if attr["in"] and not attr.out and not attr.ref then
                return "LPCWSTR"
              else
                return "LPWSTR"
              end
            end,
    set = function (args)
            return args[1] .. " = comgen_towstr(L, " .. args[2] .. ");"
          end,
    push = function (args)
             return "comgen_pushwstr(L, " .. args[1] .. ");"
           end,
    clear = function (args)
              return "comgen_clearwstr((wchar_t *)" .. args[1] .. ");"
            end,
  },
  safearray = {
    ctype = function (type)
              return "SAFEARRAY *"
            end,
    set = function (args)
            return template_set_safearray{ name = args[1], stkidx = args[2],
                                           lbound = args[3].lbound or 0,
                                           elem = {
                                             set = comtypes[args[3].elem.name].set,
                                             ctype = comtypes[args[3].elem.name].ctype(args[3].elem, args[3].elem.attr or {}),
                                             init = comtypes[args[3].elem.name].init,
                                             type = args[3].elem,
                                             vt = comtypes[args[3].elem.name].vt
                                           }, ["if"] = cosmo.cif }
          end,
    push = function (args)
             return template_push_safearray{ name = args[1],
                                            elem = {
                                              ctype = comtypes[args[2].elem.name].ctype(args[2].elem, args[2].elem.attr or {}),
                                              push = comtypes[args[2].elem.name].push,
                                              type = args[2].elem,
                                            }, ["if"] = cosmo.cif }
           end,
    clear = function (args)
              return "SafeArrayDestroy(" .. args[1] .. ");"
            end
  },
  string = {
    ctype = function (type, attr)
              if attr.ctype then return attr.ctype end
              if attr["in"] and not attr.out and not attr.ref then
                return "LPCSTR"
              else
                return "LPSTR"
              end
            end,
    set = function (args)
            return args[1] .. " = (LPSTR)lua_tostring(L, " .. args[2] .. ");"
          end,
    push = function (args)
             return "lua_pushstring(L, " .. args[1] .. ");"
           end
  },
  interface = {
    vt = "UNKNOWN",
    ctype = function (type)
              return type.ifname .. " *"
            end,
    set = function (args)
            local type = args[3]
            return args[1] .. " = (" .. type.ifname .. " *)comgen_tointerface(L, " .. args[2] .. ", \"" .. type.iid .. "\");"
          end,
    push = function (args)
             local type = args[2]
             local attr = args[3]
             if attr and attr.iid_is then
               return "comgen_pushinterface(L, " .. args[1] .. ", __" .. attr.iid_is .. "_siid);"
             else
               return "comgen_pushinterface(L, " .. args[1] .. ", \"" .. type.iid .. "\");"
             end
           end,
  },
  refiid = {
    ctype = function (type)
              return "IID"
            end,
    set = function (args)
            return template_set_refiid{ stkidx = args[2], var = args[1],
                                        strip = function (s)
                                                      if not tonumber(s) then
                                                    return s:gsub(" ", "_"):gsub("%+", "__"):gsub("%[","__"):gsub("%]","__")
                                                  else
                                                    return s
                                                  end
                                                end }
          end,
    push = function (args)
             return template_push_refiid{ var = args[1],
                                          strip = function (s)
                                                    if not tonumber(s) then
                                                      return s:gsub(" ", "_"):gsub("%+", "__"):gsub("%[","__"):gsub("%]","__")
                                                    else
                                                      return s
                                                    end
                                                  end }
           end
  },
  hresult = {
    ctype = function (type)
              return "HRESULT"
            end,
    set = function (args)
            return args[1] .. " = lua_tointeger(L, " .. args[2] .. ");"
          end,
    push = function (args)
             return [[
                 if(!SUCCEEDED(]] .. args[1] .. [[)) {
                   char sz[1024];
                   if (!FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, 0, ]] .. args[1] .. [[, 0, sz, 1024, 0))
                     lua_pushinteger(L, ]] .. args[1] .. [[);
                   else
                     lua_pushstring(L, sz);
                 } else lua_pushstring(L, "OK");
             ]]
           end
  }
}

_M.types = {
  bool = { name = "bool" },
  long = { name = "long" },
  short = { name = "short" },
  word = { name = "unsigned short" },
  char = { name = "char" },
  byte = { name = "unsigned char" },
  int = { name = "int" },
  dword = { name = "unsigned long" },
  float = { name = "float" },
  double = { name = "double" },
  variant = { name = "variant" },
  bstring = { name = "bstring" },
  tstring = { name = "tstring" },
  wstring = { name = "wstring" },
  string = { name = "string" },
  refiid = { name = "refiid" },
  hresult = { name = "hresult" },
  enum = function (typedef)
           return { name = "enum", typedef = typedef }
         end,
  struct = function (typedef, fields)
             local t = { name = "struct", typedef = typedef }
             for _, field in ipairs(fields) do
               if field.type == "self" then
                 field.type = t
               end
             end
             t.fields = fields
             return t
           end,
  array = function (type, attr)
            return { name = "array", elem_type = type, attributes = attr }
          end,
  interface = function (ifdesc)
                return { name = "interface", ifname = ifdesc.name, iid = ifdesc.iid }
              end,
  safearray = function (vartype, lbound)
                return { name = "safearray", lbound = lbound, elem = vartype }
              end
}

_M.types.vartype = {
  name = "VARTYPE",
  fields = {
    { name = "VT_EMPTY", value = 0 },
    { name = "VT_NULL", value = 1 },
    { name = "VT_I2", value = 2 },
    { name = "VT_I4", value = 3 },
    { name = "VT_R4", value = 4 },
    { name = "VT_R8", value = 5 },
    { name = "VT_CY", value = 6 },
    { name = "VT_DATE", value = 7 },
    { name = "VT_BSTR", value = 8 },
    { name = "VT_DISPATCH", value = 9 },
    { name = "VT_ERROR", value = 10 },
    { name = "VT_BOOL", value = 11 },
    { name = "VT_VARIANT", value = 12 },
    { name = "VT_UNKNOWN", value = 13 },
    { name = "VT_UI1", value = 17 },
  }
}

function _M.readfile(filename, s)
  local file, err = io.open(filename)
  if file then
    local s = file:read("*a")
    file:close()
    return s
  else
    error(err)
  end
end

function _M.writefile(filename, s)
  local file, err = io.open(filename, "w+")
  if file then
    file:write(s)
    file:close()
  else
    error(err)
  end
end

function _M.compile_method(method)
  local mdata = {
    methodname = method.name,
    cname = method.name,
    nresults = 0,
    parameters = {}
  }
  local attr = method.attributes or {}
  if attr.propget then
    mdata.cname = "get_" .. method.name
    mdata.methodname = mdata.cname
  end
  if attr.propput then
    mdata.cname = "set_" .. method.name
    mdata.methodname = mdata.cname
  end
  local pos = 2
  for i, param in ipairs(method.parameters) do
    local typename = param.type.name
    local pdata = { name = param.name, pass = param.name, type = param.type,
                    ctype = comtypes[typename].ctype(param.type, param.attributes or {}),
                    init = comtypes[typename].init,
                    clear = comtypes[typename].clear, pos = pos,
                    attr = param.attributes or {} }
    local attr = pdata.attr
    if attr.out and not attr.retval then
      mdata.nresults = mdata.nresults + 1
      pdata.pass = "&" .. param.name
      pdata.push = comtypes[typename].push
    end
    if attr.unique then
      pdata.pass = "NULL"
    end
    if attr.retval then
      mdata.nresults = mdata.nresults + 1
      pdata.pass = "&" .. param.name
      mdata.pushret = comtypes[typename].push{ param.name, param.type, param.attr }
    end
    if attr["in"] and not attr.unique then
      pos = pos + 1
      pdata.set = comtypes[typename].set
    end
    if attr.ref and not attr.out and not attr.retval then
      pdata.pass = "&" .. param.name
    end
    table.insert(mdata.parameters, pdata)
  end
  return mdata
end

function _M.compile_wrapper_method(method)
  local mdata = {
    methodname = method.name,
        cname = method.name,
    nargs = 0,
    nresults = 0,
    parameters = {}
  }
  local attr = method.attributes or {}
  if attr.propget then
    mdata.cname = "get_" .. method.name
    mdata.methodname = mdata.cname
  end
  if attr.propput then
    mdata.cname = "set_" .. method.name
    mdata.methodname = mdata.cname
  end
  local pos = 2
  for i = 1, #method.parameters, 1 do
    local param = method.parameters[i]
    local typename = param.type.name
    local pdata = { name = param.name, type = param.type,
                    ctype = comtypes[typename].ctype(param.type,               param.attributes or {}),
                    pos = "__top + " .. pos, attr = param.attributes or {} }
    local attr = pdata.attr
    if attr.out or attr.retval then
      pos = pos + 1
      pdata.name = "*" .. pdata.name
          pdata.init = comtypes[typename].init
      pdata.set = comtypes[typename].set
      mdata.nresults = mdata.nresults + 1
    end
    if attr["in"] and not attr.unique then
      pdata.init = nil
      pdata.push = comtypes[typename].push
      mdata.nargs = mdata.nargs + 1
    end
    if attr.ref and not attr.out and not attr.retval then
      pdata.name = "*" .. pdata.name
    end
    mdata.parameters[i] = pdata
  end
  return mdata
end

function _M.compile_interface(interface)
  local ifdata = {
    modname = string.lower(interface.name),
    ifname = interface.name,
    iid = interface.iid,
    parent = interface.parent.name,
    parent_iid = interface.parent.iid,
    methods = {},
    concat = cosmo.concat,
    ["if"] = cosmo.cif
  }
  for _, method in ipairs(interface.methods) do
    table.insert(ifdata.methods, _M.compile_method(method))
  end
  return ifdata
end

function _M.compile_wrapper_interface(interface)
  local ifdata = {
    ifname = interface.name,
    iid = interface.iid,
    parent = interface.parent.name,
    parent_iid = interface.parent.iid,
    methods = {},
    concat = cosmo.concat,
    ["if"] = cosmo.cif
  }
  for _, method in ipairs(interface.methods) do
    table.insert(ifdata.methods, _M.compile_wrapper_method(method))
  end
  return ifdata
end

function _M.compile_wrapper(name, interfaces)
  local wdata = {
    wname = name,
    interfaces = {}
  }
  for _, interface in ipairs(interfaces) do
    table.insert(wdata.interfaces, _M.compile_wrapper_interface(interface))
  end
  return wdata
end

function _M.compile(library)
  local modname = library.luamodule
  if modname == nil then
    modname = library.modname
  else
    modname = string.gsub(modname, "%.", "_")
  end
  local libdata = {
    modname = modname,
    header = library.header or library.modname,
    interfaces = {}, enums = library.enums or {},
    wrappers = {},
    builtin = library.builtin,
    ["if"] = cosmo.cif
  }
  for _, interface in ipairs(library.interfaces) do
    table.insert(libdata.interfaces, _M.compile_interface(interface))
  end
  for name, interfaces in pairs(library.wrappers or {}) do
    table.insert(libdata.wrappers, _M.compile_wrapper(name, interfaces))
  end
  return template(libdata), template_def(libdata),
    template_wrapper(libdata):gsub("&%*", ""):gsub("_%*", "_")
end

return _M
