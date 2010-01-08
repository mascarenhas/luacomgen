
local cosmo = require "cosmo"

local _M = {}

local template = cosmo.compile(require("comgen.template"))
local template_def = cosmo.compile[[
EXPORTS
    luaopen_$modname
]]

local template_init_enum = cosmo.compile[[
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

local comtypes = {
  long = {
    ctype = function (type)
	      return type.name
	    end,
    init = function (args)
	     return args[1] .. " = luaL_checkinteger(L, " .. args[2] .. ");" 
	   end,
    push = function (args)
	     return "lua_pushinteger(L, " .. args[1] .. ");"
	   end
  },
  enum = {
    ctype = function (type)
	      return type.typedef
	    end,
    init = function (args)
	     return template_init_enum{ type = args[3], stkidx = args[2], var = args[1] }
	   end,
    push = function (args)
	     return template_push_enum{ type = args[2], var = args[1] }
	   end,
  }
}

_M.types = {
  long = { name = "long" },
  enum = function (typedef)
	   return { name = "enum", typedef = typedef }
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
  end
  if attr.propset then
    mdata.cname = "set_" .. method.name
  end
  for i, param in ipairs(method.parameters) do
    local typename = param.type.name
    local pdata = { name = param.name, pass = param.name, type = param.type,
		    ctype = comtypes[typename].ctype(param.type), pos = i + 1 }
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
      pdata.init = comtypes[typename].init
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
