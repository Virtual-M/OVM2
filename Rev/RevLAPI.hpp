#pragma once

#include "RevBase.hpp"

void r_lua_settop(r_lua_State rL, signed int idx);
void r_lua_pushlightuserdata(r_lua_State RL, void* ud);