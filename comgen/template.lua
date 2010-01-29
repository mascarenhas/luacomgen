
return [==[

#include <stdio.h>
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

#define GUID_SIZE 39

#ifndef IID_IUnknown_String
#define IID_IUnknown_String "{00000000-0000-0000-C000-000000000046}"
#endif

#ifndef IID_IDispatch_String
#define IID_IDispatch_String "{00020400-0000-0000-C000-000000000046}"
#endif

static int comgen_error(lua_State *L, HRESULT hr) {
  char sz[1024];
  if (!FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, 0, hr, 0, sz, 1024, 0))
    strcpy(sz, "Unknown error");
  luaL_error(L, sz);
  return 0;
}

static int comgen_isinterface(lua_State *L, int stkidx, const char *siid) {
  lua_getfield(L, LUA_REGISTRYINDEX, "luacomgen_metatables");
  lua_getmetatable(L, stkidx);
  if(!lua_isnil(L, -1)) {
    lua_gettable(L, -2);
    if(!lua_isnil(L, -1)) {
      if(siid) {
	lua_pushstring(L, siid);
	if(lua_rawequal(L, -1, -2)) {
	  lua_pop(L, 3);
	  return 1;
	}
      } else {
	lua_pop(L, 2);
	return 1;
      }
    }
  }
  return 0;
}

static void *comgen_checkinterface(lua_State *L, int stkidx, const char *siid) {
  if(comgen_isinterface(L, stkidx, siid)) {
    void **ud = (void **)lua_touserdata(L, stkidx);
    return *ud;
  }
  if(siid)
    luaL_error(L, "expected COM interface %s, got %s", siid, lua_typename(L, lua_type(L, stkidx)));
  else
    luaL_error(L, "expected COM interface, got %s", lua_typename(L, lua_type(L, stkidx)));
  return 0;
}

static int comobject_gc(lua_State *L) {
  IUnknown *p = (IUnknown *)comgen_checkinterface(L, 1, 0);
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
  lua_pushvalue(L, -1);
  lua_setfield(L, -3, iid_string);
  lua_pushstring(L, iid_string);
  lua_settable(L, -3);
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

static wchar_t *comgen_towstr(lua_State *L, int stkidx) {
  const char *s = lua_tostring(L, stkidx);
  int size = MultiByteToWideChar(CP_UTF8, 0, s, -1, 0, 0);
  wchar_t *ws = new wchar_t[size];
  MultiByteToWideChar(CP_UTF8, 0, s, -1, ws, size);
  return ws;
}

static void comgen_pushwstr(lua_State *L, wchar_t *ts) {
  int size = WideCharToMultiByte(CP_UTF8, 0, ts, -1, /* s */ 0, /* size */ 0, 0, 0);
  char *s = new char[size];
  WideCharToMultiByte(CP_UTF8, 0, ts, -1, s, size, 0, 0);
  lua_pushstring(L, s);
  delete s;
}

static void comgen_clearwstr(wchar_t *ts) {
  #ifdef UNICODE
    delete s;
  #endif
}

static BSTR comgen_tobstr(lua_State *L, int stkidx) {
  wchar_t *ws = comgen_towstr(L, stkidx);
  BSTR b = SysAllocString(ws);
  delete ws;
  return b;
}

static void comgen_pushbstr(lua_State *L, BSTR b) {
  b = b ? b : OLESTR("");
  comgen_pushwstr(L, b);
}

static TCHAR *comgen_totstr(lua_State *L, int stkidx) {
  #ifdef UNICODE
    return comgen_towstr(L, stkidx);
  #else
    return (TCHAR*)lua_tostring(L, stkidx);
  #endif
}

static void comgen_pushtstr(lua_State *L, TCHAR *ts) {
  #ifdef UNICODE
    comgen_pushwstr(L, ts);
  #else
    lua_pushstring(L, ts);
  #endif
}

static void comgen_cleartstr(TCHAR *ts) {
  #ifdef UNICODE
    comgen_clearwstr(ts);
  #endif
}

#define ISREF(T) (isref ? *(var->p##T) : var->T)

#define ISREF_S(T,V) if(isref) { luaL_error(L, "not supported"); } else { var->T=V; }

#define VT(T) { VT_##T, #T }

typedef struct {
  VARTYPE vt;
  const char *name;
} COMGEN_VARTYPE;

static COMGEN_VARTYPE comgen_vartypes[] = { 
  VT(EMPTY),
  VT(NULL),
  VT(UI1),
  VT(UI2),
  VT(UI4),
  VT(UI8),
  VT(UINT),
  VT(I1),
  VT(I2),
  VT(I4),
  VT(I8),
  VT(INT),
  VT(R4),
  VT(R8),
  VT(DATE),
  VT(BSTR),
  VT(ERROR),
  VT(BOOL),
  VT(VARIANT),
  { 0, NULL }
};

static VARTYPE comgen_name2vt(lua_State *L, const char *name) {
  COMGEN_VARTYPE *vts = comgen_vartypes;
  for(; vts->name != NULL; vts++) {
    if(strcmp(vts->name, name) == 0)
      return vts->vt;
  }
  luaL_error(L, "invalid VARTYPE %s", name);
  return 0;
}

static void comgen_checktype(lua_State *L, int origidx, int validx, int t) {
  int rt = lua_type(L, validx);
  if(rt != t)
    luaL_error(L, "argument %i needs to be a %s but is a %s", 
	       origidx, lua_typename(L, t), lua_typename(L, rt));
}

static void *comgen_tointerface(lua_State *L, int stkidx, const char *siid) {
  wchar_t wsiid[GUID_SIZE];
  mbstowcs(wsiid, siid, GUID_SIZE);
  IID iid;
  IUnknown *ppv;
  HRESULT hr;
  hr = IIDFromString(wsiid, &iid);
  if(SUCCEEDED(hr)) {
    IUnknown *p = (IUnknown *)comgen_checkinterface(L, stkidx, 0);
    hr = p->QueryInterface(iid, (void**)&ppv);
    if(SUCCEEDED(hr)) {
      return ppv;
    } else {
      comgen_error(L, hr);
    }
  } else {
    comgen_error(L, hr);
  }
  return 0;
}

static void comgen_pushinterface(lua_State *L, void *ppv, const char *siid) {
  void **ud = (void **)lua_newuserdata(L, sizeof(void *));
  lua_getfield(L, LUA_REGISTRYINDEX, "luacomgen_metatables");
  lua_getfield(L, -1, siid);
  if(lua_isnil(L, -1)) {
    ((IUnknown*)ppv)->Release();
    luaL_error(L, "interface %s not registered", siid);
  }
  lua_setmetatable(L, -3);
  lua_pop(L, 1);
  *ud = ppv;
}

static void comgen_set_variant(lua_State *L, int stkidx, VARIANT *var);

static void comgen_converttable(lua_State *L, int stkidx, VARIANT *var) {
  lua_getfield(L, stkidx, "type");
  VARTYPE vt = comgen_name2vt(L, lua_tostring(L, -1));
  lua_getfield(L, stkidx, "value");
  int isref = 0;
  switch(vt) {
    case VT_EMPTY: break;
    case VT_NULL: break;
    case VT_UI1: ISREF_S(bVal, lua_tointeger(L, -1)); break;
    case VT_UI2: ISREF_S(uiVal, lua_tointeger(L, -1)); break;
    case VT_UI4: ISREF_S(ulVal, lua_tointeger(L, -1)); break;
    case VT_UI8: ISREF_S(ullVal, lua_tointeger(L, -1)); break;
    case VT_UINT: ISREF_S(uintVal, lua_tointeger(L, -1)); break;
    case VT_I1: ISREF_S(cVal, lua_tointeger(L, -1)); break;
    case VT_I2: ISREF_S(iVal, lua_tointeger(L, -1)); break;
    case VT_I4: ISREF_S(lVal, lua_tointeger(L, -1)); break;
    case VT_I8: ISREF_S(llVal, lua_tointeger(L, -1)); break;
    case VT_INT: ISREF_S(intVal, lua_tointeger(L, -1)); break;
    case VT_R4: ISREF_S(fltVal, lua_tonumber(L, -1)); break;
    case VT_R8: ISREF_S(dblVal, lua_tonumber(L, -1)); break;
    case VT_CY: luaL_error(L, "VARIANT type CY not supported"); break;
    case VT_DATE: ISREF_S(date, lua_tonumber(L, -1)); break;
    case VT_BSTR: {
      ISREF_S(bstrVal, comgen_tobstr(L, -1));
      break;
    }
    case VT_DISPATCH:
      ISREF_S(pdispVal, (IDispatch *)comgen_tointerface(L, -1, IID_IDispatch_String));
      break;
    case VT_ERROR: {
      ISREF_S(scode, lua_tointeger(L, -1));
      break;
    }
    case VT_BOOL: {
      ISREF_S(boolVal, lua_toboolean(L, -1) ? -1 : 0);
      break;
    }
    case VT_VARIANT: comgen_set_variant(L, lua_gettop(L), var->pvarVal); break;
    case VT_UNKNOWN:
      ISREF_S(punkVal, (IUnknown *)comgen_tointerface(L, -1, IID_IUnknown_String));
      break;
    case VT_DECIMAL: luaL_error(L, "VARIANT type DECIMAL not supported"); break;
    default: luaL_error(L, "unsupported VARIANT type %i", vt);
  }
  lua_pop(L, 2);
  var->vt = vt;
}

static void comgen_set_variant(lua_State *L, int stkidx, VARIANT *var) {
  int t = lua_type(L, stkidx);
  switch(t) {
    case LUA_TNUMBER:
      var->vt = VT_R8;
      var->dblVal = lua_tonumber(L, stkidx);
      break;
    case LUA_TSTRING: {
      var->vt = VT_BSTR;
      var->bstrVal = comgen_tobstr(L, stkidx);
      break;
    }
    case LUA_TNIL:
      var->vt = VT_EMPTY;
      break;
    case LUA_TBOOLEAN:
      var->vt = VT_BOOL;
      var->boolVal = lua_toboolean(L, stkidx) ? -1 : 0;
      break;
    case LUA_TTABLE:
      comgen_converttable(L, stkidx, var);
      break;
    case LUA_TUSERDATA: {
      if(comgen_isinterface(L, stkidx, 0)) {
	var->vt = VT_UNKNOWN;
	var->punkVal = (IUnknown *)comgen_tointerface(L, stkidx, 0);
	break;
      }
    }
    default:
      luaL_error(L, "%s is not a valid type for COM variants", lua_typename(L, t));
  }
}

static void comgen_push_variant(lua_State *L, VARIANT *var) {
  VARTYPE vt = var->vt;
  VARTYPE isref = var->vt & VT_BYREF;
  vt = var->vt & ~VT_BYREF;
  switch(vt) {
    case VT_EMPTY: lua_pushnil(L); break;
    case VT_NULL: lua_pushnil(L); break;
    case VT_UI1: lua_pushinteger(L, ISREF(bVal)); break;
    case VT_UI2: lua_pushinteger(L, ISREF(uiVal)); break;
    case VT_UI4: lua_pushinteger(L, ISREF(ulVal)); break;
    case VT_UI8: lua_pushinteger(L, (long)ISREF(ullVal)); break;
    case VT_UINT: lua_pushinteger(L, ISREF(uintVal)); break;
    case VT_I1: lua_pushinteger(L, ISREF(cVal)); break;
    case VT_I2: lua_pushinteger(L, ISREF(iVal)); break;
    case VT_I4: lua_pushinteger(L, ISREF(lVal)); break;
    case VT_I8: lua_pushinteger(L, (long)ISREF(llVal)); break;
    case VT_INT: lua_pushinteger(L, ISREF(intVal)); break;
    case VT_R4: lua_pushnumber(L, ISREF(fltVal)); break;
    case VT_R8: lua_pushnumber(L, ISREF(dblVal)); break;
    case VT_CY: luaL_error(L, "VARIANT type CY not supported"); break;
    case VT_DATE: lua_pushnumber(L, ISREF(date)); break;
    case VT_BSTR: {
      comgen_pushbstr(L, ISREF(bstrVal));
      break;
    }
    case VT_DISPATCH: 
      comgen_pushinterface(L, ISREF(pdispVal), IID_IDispatch_String);
      break;
    case VT_ERROR: {
      char sz[1024];
      if (!FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, 0, ISREF(scode), 0, sz, 1024, 0))
	lua_pushstring(L, sz);
      else
	lua_pushstring(L, "Unknown error");
      break;
    }
    case VT_BOOL: {
      ISREF(boolVal) == -1 ? lua_pushboolean(L, 1) : lua_pushboolean(L, 0);
      break;
    }
    case VT_VARIANT: comgen_push_variant(L, var->pvarVal); break;
    case VT_UNKNOWN: 
      comgen_pushinterface(L, ISREF(punkVal), IID_IUnknown_String);
      break;
    case VT_DECIMAL: luaL_error(L, "VARIANT type DECIMAL not supported"); break;
    default: luaL_error(L, "unsupported VARIANT type %i", vt);
  }
}


$interfaces[[

#ifndef IID_$(parent)_String
#define IID_$(parent)_String "$parent_iid"
#endif
#ifndef IID_$(ifname)_String
#define IID_$(ifname)_String "$iid"
#endif

$methods[[
static int $(modname)_$(methodname)(lua_State *L) {
  $ifname *p = ($ifname *)comgen_checkinterface(L, 1, IID_$(ifname)_String);
$parameters[[  $ctype $name;
$if{init}[[  $init{name, type}
]]
$if{set}[[  $set{name, pos, type}
]]]]
  HRESULT hr = p->$cname($concat{parameters}[[$pass]]);
  if(SUCCEEDED(hr)) {
    $pushret
$parameters[[$if{push}[[    $push{name,type}
]]
$if{clear}[[    $clear{name,type}
]]]]    return $nresults;
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
