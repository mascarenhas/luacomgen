
local cosmo = require "cosmo"

local _M = {}

local template = cosmo.compile(require("comgen.template"))
local template_def = cosmo.compile[[
EXPORTS
    luaopen_$modname
]]

local comtypes = {
  long = {
    init = function (args)
	     return args[1] .. " = luaL_checkinteger(L, " .. args[2] .. ");" 
	   end,
    push = function (args)
	     return "lua_pushinteger(L, " .. args[1] .. ");"
	   end
  },
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
    local pdata = { name = param.name, pass = param.name, type = param.type, pos = i + 1 }
    local attr = param.attributes or {}
    if attr.out and not attr.retval then
      mdata.nresults = mdata.nresults + 1
      pdata.pass = "&" .. param.name
      pdata.push = comtypes[param.type].push
    end
    if attr.retval then
      mdata.nresults = mdata.nresults + 1
      pdata.pass = "&" .. param.name
      mdata.pushret = comtypes[param.type].push{ param.name }
    end
    if attr["in"] then
      pdata.init = comtypes[param.type].init
    end
    table.insert(mdata.parameters, pdata)
  end
  return mdata
end

function _M.compile(interface)
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
  return template(ifdata), template_def(ifdata)
end

return _M
