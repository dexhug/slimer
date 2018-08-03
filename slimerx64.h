// slimerx64 - Declarations for x64 systems

#ifdef _WINDLL
#define SLIMER __declspec(dllexport)
#else
#define SLIMER __declspec(dllimport)
#endif

#include <windows.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

extern "C" SLIMER int slimer_qpf(lua_State *L);
extern "C" SLIMER int slimer_qpc(lua_State *L);
extern "C" SLIMER int slimer_sleep(lua_State *L);
extern "C" SLIMER int slimer_msleep(lua_State *L);
extern "C" SLIMER int slimer_usleep(lua_State *L);
extern "C" SLIMER int slimer_period(lua_State *L);
extern "C" SLIMER int luaopen_slimerx64(lua_State *L);