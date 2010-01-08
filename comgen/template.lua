
return [==[

#include "$(modname).h"
#include "$(modname)_i.c"

extern "C" {
  #include "lua.h"
  #include "lualib.h"
  #include "lauxlib.h"
}

#define IID_$(parent)_String "$parent_iid"
#define IID_$(ifname)_String "$iid"

static int comgen_error(lua_State *L, HRESULT hr) {
  char sz[1024];
  if (!FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, 0, hr, 0, sz, 1024, 0))
    strcpy(sz, "Unknown error");
  luaL_error(L, sz);
  return 0;
}

$methods[[
static int $(modname)_$(methodname)(lua_State *L) {
  void *ud = lua_touserdata(L, 1);
  $ifname *p = *(($ifname **)ud);
$parameters[[  $type $name;
$if{init}[[  $init{name, pos}
]]]]
  HRESULT hr = p->$cname($concat{parameters}[[$pass]]);
  if(SUCCEEDED(hr)) {
    $pushret
$parameters[[$if{push}[[    $push{name};
]]]]
    return $nresults;
  } else {
    return comgen_error(L, hr);
  }
}
]]

static int comobject_gc(lua_State *L) {
  void *ud = lua_touserdata(L, 1);
  IUnknown *p = *((IUnknown **)ud);
  p->Release();
  p = NULL;
  return 0;
}

static luaL_Reg $(modname)_methods[] = {
$methods[[  { "$methodname", $(modname)_$methodname },
]]
  { NULL, NULL }
};

static void $(modname)_registermeta(lua_State *L) {
  lua_getfield(L, LUA_REGISTRYINDEX, "luacomgen_metatables");
  lua_newtable(L);
  lua_pushvalue(L, -3);
  lua_setfield(L, -2, "__index");
  lua_pushcfunction(L, comobject_gc);
  lua_setfield(L, -2, "__gc");
  lua_pushstring(L, "$ifname");
  lua_setfield(L, -2, "__type");
  lua_setfield(L, -2, IID_$(ifname)_String);
}

extern "C" int luaopen_$modname(lua_State *L) {
  lua_newtable(L);
  int i = lua_gettop(L);
  lua_getfield(L, LUA_REGISTRYINDEX, "luacomgen_metatables");
  lua_getfield(L, -1, IID_$(parent)_String);
  lua_getfield(L, -1, "__index");
  lua_setfield(L, i, "__index");
  lua_settop(L, i);
  lua_pushvalue(L, -1);
  lua_setmetatable(L, -2);
  luaL_register(L, NULL, $(modname)_methods);
  $(modname)_registermeta(L);
  lua_pushboolean(L, 1);
  return 1;
}

]==]
