
#include "RevLAPI.hpp"
#include "../Lua/lobject.h"

void rev_lua_settop(DWORD rL, signed int idx)
{
	if (idx < 0)
	{
		*(DWORD*)(rL + 16) += 16 * idx + 16;
	}
	else
	{
		int i;
		for (i = 16 * idx; *(DWORD*)(rL + 16) < (unsigned int)(i + *(DWORD*)(rL + 28)); *(DWORD*)(rL + 16) += 16)
			*(DWORD*)(*(DWORD*)(rL + 16) + 8) = 0;
		*(DWORD*)(rL + 16) = i + *(DWORD*)(rL + 28);
	}
}

void rev_lua_pushlightuserdata(DWORD rL, void * ud)
{
	TValue* upv = (TValue*)(*(DWORD*)(rL + 16));
	upv->tt = R_LUA_TLIGHTUSERDATA;
	upv->value.p = ud;
	*(DWORD*)(rL + 16) += 16;
}
