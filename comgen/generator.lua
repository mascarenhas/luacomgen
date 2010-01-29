
local cosmo = require "cosmo"

local _M = {}

local template = cosmo.compile(require("comgen.template"))
local template_def = cosmo.compile[[
EXPORTS
    luaopen_$modname
]]

local template_set_enum = cosmo.compile[[
  lua_getfield(L, LUA_REGISTRYINDEX, "luacomgen_enums");
  lua_getfield(L, -1, "$(type.typedef)");
  lua_pushvalue(L, $stkidx);
  lua_gettable(L, -2);
  $var = ($(type.typedef))luaL_checkinteger(L, -1);
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
    $if{init}[[$init{ var.."."..name, type }]]
  ]]
]=]

local template_set_struct = cosmo.compile[=[
  $fields[[
    $if{set}[[
      lua_getfield(L, $stkidx, "$name");
      $set{ var.."."..name, -1, type }
      lua_pop(L, 1);
    ]]
  ]]
]=]

local template_push_struct = cosmo.compile[=[
  lua_newtable(L);
  $fields[[
    $if{push}[[$push{ var.."."..name, type }
	  lua_setfield(L, -2, "$name");]]
  ]]
]=]

local template_clear_struct = cosmo.compile[=[
  $fields[[
    $if{clear}[[$clear{ var.."."..name, type }]]
  ]]
]=]

local comtypes 
comtypes = {
  long = {
    ctype = function (type)
	      return type.name
	    end,
    set = function (args)
	    return args[1] .. " = luaL_checkinteger(L, " .. args[2] .. ");" 
	  end,
    push = function (args)
	     return "lua_pushinteger(L, " .. args[1] .. ");"
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
	    return template_set_struct{ fields = fields, stkidx = args[2], var = args[1], ["if"] = cosmo.cif }
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
    ctype = function (type)
	      return "LPTSTR"
	    end,
    set = function (args)
	    return args[1] .. " = comgen_totstr(L, " .. args[2] .. ");"
	  end,
    push = function (args)
	     return "comgen_pushtstr(L, " .. args[1] .. ");"
	   end,
    clear = function (args)
	      return "comgen_cleartstr(" .. args[1] .. ");"
	    end,
  },
  wstring = {
    ctype = function (type)
	      return "LPWSTR"
	    end,
    set = function (args)
	    return args[1] .. " = comgen_towstr(L, " .. args[2] .. ");"
	  end,
    push = function (args)
	     return "comgen_pushwstr(L, " .. args[1] .. ");"
	   end,
    clear = function (args)
	      return "comgen_clearwstr(" .. args[1] .. ");"
	    end,
  },
  string = {
    ctype = function (type)
	      return "LPSTR"
	    end,
    set = function (args)
	    return args[1] .. " = (char*)lua_tostring(L, " .. args[2] .. ");"
	  end,
    push = function (args)
	     return "lua_pushstring(L, " .. args[1] .. ");"
	   end
  },
  interface = {
    ctype = function (type)
	      return type.ifname .. " *"
	    end,
    set = function (args)
	    local type = args[3]
	    return args[1] .. " = (" .. type.ifname .. " *)comgen_tointerface(L, " .. args[2] .. ", \"" .. type.iid .. "\");"
	  end,
    push = function (args)
	     local type = args[2]
	     return "comgen_pushinterface(L, " .. args[1] .. ", \"" .. type.iid .. "\");"
	   end,
  }
}

_M.types = {
  long = { name = "long" },
  variant = { name = "variant" },
  bstring = { name = "bstring" },
  tstring = { name = "tstring" },
  wstring = { name = "wstring" },
  string = { name = "string" },
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
  interface = function (ifdesc)
		return { name = "interface", ifname = ifdesc.name, iid = ifdesc.iid }
	      end
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
  for i, param in ipairs(method.parameters) do
    local typename = param.type.name
    local pdata = { name = param.name, pass = param.name, type = param.type,
		    ctype = comtypes[typename].ctype(param.type),
		    init = comtypes[typename].init,
		    clear = comtypes[typename].clear, pos = i + 1 }
    local attr = param.attributes or {}
    if attr.out and not attr.retval then
      mdata.nresults = mdata.nresults + 1
      pdata.pass = "&" .. param.name
      pdata.push = comtypes[typename].push
    end
    if attr.retval then
      mdata.nresults = mdata.nresults + 1
      pdata.pass = "&" .. param.name
      mdata.pushret = comtypes[typename].push{ param.name, param.type }
    end
    if attr["in"] then
      pdata.set = comtypes[typename].set
    end
    if attr.ref and not attr.out and not attr.retval then
      pdata.pass = "&" .. param.name
    end
    table.insert(mdata.parameters, pdata)
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

function _M.compile(library)
  local libdata = {
    modname = library.modname,
    header = library.header or library.modname,
    interfaces = {}, enums = library.enums or {}
  }
  for _, interface in ipairs(library.interfaces) do
    table.insert(libdata.interfaces, _M.compile_interface(interface))
  end
  return template(libdata), template_def(libdata)
end

return _M
