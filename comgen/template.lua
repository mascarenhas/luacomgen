
return [==[

#include "$(header).h"
#include "$(header)_i.c"

extern "C" {
  #include "lua.h"
  #include "lualib.h"
  #include "lauxlib.h"
}

typedef struct {
  char *name;
  int value;
} comgen_enum;

static int comgen_error(lua_State *L, HRESULT hr) {
  char sz[1024];
  if (!FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, 0, hr, 0, sz, 1024, 0))
    strcpy(sz, "Unknown error");
  luaL_error(L, sz);
  return 0;
}

static int comobject_gc(lua_State *L) {
  void *ud = lua_touserdata(L, 1);
  IUnknown *p = *((IUnknown **)ud);
  p->Release();
  p = NULL;
  return 0;
}

static void comgen_registermeta(lua_State *L, const char *iid_string, const char *ifname) {
  lua_getfield(L, LUA_REGISTRYINDEX, "luacomgen_metatables");
  lua_newtable(L);
  lua_pushvalue(L, -3);
  lua_setfield(L, -2, "__index");
  lua_pushcfunction(L, comobject_gc);
  lua_setfield(L, -2, "__gc");
  lua_pushstring(L, ifname);
  lua_setfield(L, -2, "__type");
  lua_setfield(L, -2, iid_string);
  lua_pop(L, 1);
}

static void comgen_fillmethods(lua_State *L, const char *iid_parent_string, 
			       const char *iid_string, const char *ifname, const luaL_Reg *methods) {
  lua_newtable(L);
  int i = lua_gettop(L);
  lua_getfield(L, LUA_REGISTRYINDEX, "luacomgen_metatables");
  lua_getfield(L, -1, iid_parent_string);
  lua_getfield(L, -1, "__index");
  lua_setfield(L, i, "__index");
  lua_settop(L, i);
  lua_pushvalue(L, -1);
  lua_setmetatable(L, -2);
  luaL_register(L, NULL, methods);
  comgen_registermeta(L, iid_string, ifname);
}

static void comgen_registerenum(lua_State *L, const char *enum_name, const comgen_enum *fields) {
  lua_getfield(L, LUA_REGISTRYINDEX, "luacomgen_enums");
  lua_newtable(L);
  for(int i = 0; fields[i].name != NULL; i++) {
    lua_pushstring(L, fields[i].name);
    lua_pushinteger(L, fields[i].value);
    lua_settable(L, -3);
    lua_pushinteger(L, fields[i].value);
    lua_pushstring(L, fields[i].name);
    lua_settable(L, -3);
  }
  lua_setfield(L, -2, enum_name);
  lua_pop(L, 1);
}

$enums[[

static comgen_enum $(name)_fields[] = {
$fields[[  { "$name", $value },
]]
  { NULL, 0 }
};

]]

$interfaces[[

#ifndef IID_$(parent)_String
#define IID_$(parent)_String "$parent_iid"
#endif
#ifndef IID_$(ifname)_String
#define IID_$(ifname)_String "$iid"
#endif

$methods[[
static int $(modname)_$(methodname)(lua_State *L) {
  void *ud = lua_touserdata(L, 1);
  $ifname *p = *(($ifname **)ud);
$parameters[[  $ctype $name;
$if{init}[[  $init{name, pos, type}
]]]]
  HRESULT hr = p->$cname($concat{parameters}[[$pass]]);
  if(SUCCEEDED(hr)) {
    $pushret
$parameters[[$if{push}[[    $push{name,type}
]]]]
    return $nresults;
  } else {
    return comgen_error(L, hr);
  }
}
]]

static luaL_Reg $(ifname)_methods[] = {
$methods[[  { "$methodname", $(modname)_$methodname },
]]
  { NULL, NULL }
};

]]

extern "C" int luaopen_$modname(lua_State *L) {
$interfaces[[
  comgen_fillmethods(L, IID_$(parent)_String, IID_$(ifname)_String, "$ifname", $(ifname)_methods);
]]
$enums[[
  comgen_registerenum(L, "$name", $(name)_fields);
]]
  lua_pushboolean(L, 1);
  return 1;
}

]==]
