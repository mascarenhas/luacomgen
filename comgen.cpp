
#define _WIN32_DCOM
#include <stdlib.h>
#include <objbase.h>
#include <unknwn.h>

extern "C" {
  #include "lua.h"
  #include "lualib.h"
  #include "lauxlib.h"
}

#define IID_IUnknown_String "{00000000-0000-0000-C000-000000000046}"

#define GUID_SIZE 39

static int comgen_error(lua_State *L, HRESULT hr) {
  char sz[1024];
  if (!FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, 0, hr, 0, sz, 1024, 0))
    strcpy(sz, "Unknown error");
  luaL_error(L, sz);
  return 0;
}

static IUnknown *comgen_checkinterface(lua_State *L, int stkidx) {
  lua_getfield(L, LUA_REGISTRYINDEX, "luacomgen_metatables");
  lua_getmetatable(L, stkidx);
  if(!lua_isnil(L, -1)) {
    lua_gettable(L, -2);
    if(!lua_isnil(L, -1)) {
      lua_pop(L, 2);
      void **ud = (void **)lua_touserdata(L, stkidx);
      return (IUnknown *)(*ud);
    }
  }
  luaL_error(L, "expected COM interface, got %s", lua_typename(L, lua_type(L, stkidx)));
  return 0;
}

static int iunknown_QueryInterface(lua_State *L) {
  IUnknown *p = comgen_checkinterface(L, 1);
  size_t size;
  const char *siid = luaL_checklstring(L, 2, &size);
  if(size >= GUID_SIZE) {
    luaL_error(L, "invalid IID: too long!");
  }
  wchar_t wsiid[GUID_SIZE];
  mbstowcs(wsiid, siid, GUID_SIZE);
  IID iid;
  IUnknown *ppv;
  HRESULT hr;
  hr = IIDFromString(wsiid, &iid);
  if(SUCCEEDED(hr)) {
    hr = p->QueryInterface(iid, (void**)&ppv);
    if(SUCCEEDED(hr)) {
      void **ud = (void **)lua_newuserdata(L, sizeof(void *));
      lua_getfield(L, LUA_REGISTRYINDEX, "luacomgen_metatables");
      lua_getfield(L, -1, siid);
      if(lua_isnil(L, -1)) {
	ppv->Release();
	luaL_error(L, "interface not registered");
      }
      lua_setmetatable(L, -3);
      lua_pop(L, 1);
      *ud = ppv;
      return 1;
    } else {
      return comgen_error(L, hr);
    }
  } else {
    return comgen_error(L, hr);
  }
}

static int iunknown_AddRef(lua_State *L) {
  IUnknown *p = comgen_checkinterface(L, 1);
  long r = p->AddRef();
  lua_pushinteger(L, r);
  return 1;
}

static int iunknown_Release(lua_State *L) {
  IUnknown *p = comgen_checkinterface(L, 1);
  long r = p->Release();
  if(r == 0) {
    lua_pushnil(L);
    lua_setmetatable(L, 1);
  }
  lua_pushinteger(L, r);
  return 1;
}

static int comobject_gc(lua_State *L) {
  IUnknown *p = comgen_checkinterface(L, 1);
  p->Release();
  p = NULL;
  return 0;
}

static luaL_Reg iunknown_methods[] = {
  { "QueryInterface", iunknown_QueryInterface },
  { "AddRef", iunknown_AddRef },
  { "Release", iunknown_Release },
  { NULL, NULL }
};

static void iunknown_registermeta(lua_State *L) {
  lua_getfield(L, LUA_REGISTRYINDEX, "luacomgen_metatables");
  lua_newtable(L);
  lua_pushvalue(L, -3);
  lua_setfield(L, -2, "__index");
  lua_pushcfunction(L, comobject_gc);
  lua_setfield(L, -2, "__gc");
  lua_pushstring(L, "IUnknown");
  lua_setfield(L, -2, "__type");
  lua_pushvalue(L, -1);
  lua_setfield(L, -3, IID_IUnknown_String);
  lua_pushstring(L, IID_IUnknown_String);
  lua_settable(L, -3);
}

static int comgen_createinstance(lua_State *L) {
  size_t sizeclsid;
  int nargs = lua_gettop(L);
  const char *sclsid = luaL_checklstring(L, 1, &sizeclsid);
  if(sizeclsid >= GUID_SIZE) {
    luaL_error(L, "invalid CLSID: too long!");
  }
  wchar_t wsclsid[GUID_SIZE];
  mbstowcs(wsclsid, sclsid, GUID_SIZE);
  CLSID clsid;
  HRESULT hr;
  hr = CLSIDFromString(wsclsid, &clsid);
  if(SUCCEEDED(hr)) {
    size_t sizeiid;
    const char *siid = luaL_checklstring(L, 2, &sizeiid);
    if(sizeiid >= GUID_SIZE) {
      luaL_error(L, "invalid IID: too long!");
    }
    wchar_t wsiid[GUID_SIZE];
    mbstowcs(wsiid, siid, GUID_SIZE);
    IID iid;
    hr = IIDFromString(wsiid, &iid);
    if(SUCCEEDED(hr)) {
      IUnknown *ppv;
      MULTI_QI qi[1];
      HRESULT hr;
      qi[0].pIID = &iid;
      qi[0].pItf = NULL;
      qi[0].hr = 0;
      if(nargs == 2 || lua_isnil(L, 3)) {
	hr = CoCreateInstanceEx(clsid, 0, CLSCTX_ALL, 0 /*server*/, 1, qi);
      } else {
	COSERVERINFO si;
	size_t sizehost;
	const char *host = luaL_checklstring(L, 3, &sizehost);
	wchar_t *wshost = new wchar_t[sizehost];
	mbstowcs(wshost, host, sizehost);
	si.dwReserved1 = 0;
	si.pwszName = wshost;
	si.pAuthInfo = NULL;
	si.dwReserved2 = 0;
	hr = CoCreateInstanceEx(clsid, 0, CLSCTX_ALL, &si, 1, qi);
	delete wshost;
      }
      if(SUCCEEDED(hr) && SUCCEEDED(qi[0].hr)) {
	void **ud = (void **)lua_newuserdata(L, sizeof(void *));
	ppv = qi[0].pItf;
	lua_getfield(L, LUA_REGISTRYINDEX, "luacomgen_metatables");
	lua_getfield(L, -1, siid);
	if(lua_isnil(L, -1)) {
	  ppv->Release();
	  luaL_error(L, "interface %s not registered", siid);
	}
	lua_setmetatable(L, -3);
	lua_pop(L, 1);
	*ud = ppv;
	return 1;
      } else {
	return SUCCEEDED(hr) ? comgen_error(L, qi[0].hr) : comgen_error(L, hr);
      }
    } else {
      return comgen_error(L, hr);
    }
  } else {
    return comgen_error(L, hr);
  }
}

int comgen_messageloop(lua_State *L) {
  MSG msg;
  BOOL bRet;
  while( (bRet = GetMessage( &msg, NULL, 0, 0 )) != 0) { 
    if (bRet == -1) {
      break;
    } else {
      TranslateMessage(&msg); 
      DispatchMessage(&msg); 
    }
  }
  return 0;
}

int comgen_messagestep(lua_State *L) {
  MSG msg;
  BOOL bRet = GetMessage( &msg, NULL, 0, 0 );
  if (bRet == -1 || bRet == 0) {
  	lua_pushboolean(L, 0);
    return 1;
  } else {
    TranslateMessage(&msg); 
    DispatchMessage(&msg);
    lua_pushboolean(L, 1);
    return 1;
  }
}

static luaL_Reg comgen_functions[] = {
  { "CreateInstance", comgen_createinstance },
  { "MessageLoop", comgen_messageloop },
  { "MessageStep", comgen_messagestep },
  { NULL, NULL }
};

extern "C" int luaopen_comgen(lua_State *L) {
  HRESULT hr = CoInitializeEx(0, COINIT_APARTMENTTHREADED);
  if(SUCCEEDED(hr)) {
    lua_newtable(L);
    lua_setfield(L, LUA_REGISTRYINDEX, "luacomgen_metatables");
    lua_newtable(L);
    lua_setfield(L, LUA_REGISTRYINDEX, "luacomgen_enums");
    lua_newtable(L);
    luaL_register(L, NULL, iunknown_methods);
    iunknown_registermeta(L);
    luaL_register(L, "comgen", comgen_functions);
    lua_pushstring(L, IID_IUnknown_String);
    lua_setfield(L, -2, "IUnknown");
    return 1;
  } else {
    luaL_error(L, "failed to initialize COM subsystem");
    return 0;
  }
}
