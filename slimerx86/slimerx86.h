// slimerx86 - Declarations for x86 systems

#ifdef _WINDLL
#define SLIMER __declspec(dllexport)
#else
#define SLIMER __declspec(dllimport)
#endif

#include <windows.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

SLIMER int slimer_qpf(lua_State *L);
SLIMER int slimer_qpc(lua_State *L);
SLIMER int slimer_sleep(lua_State *L);
SLIMER int slimer_msleep(lua_State *L);
SLIMER int slimer_usleep(lua_State *L);
SLIMER int slimer_period(lua_State *L);
SLIMER int luaopen_slimerx86(lua_State *L);