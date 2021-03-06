#pragma once

#include "common/Lua.h"

namespace only2d
{
	class LuaEvent
	{
	public:
		static void openModule(lua_State *L);

	private:
		static const luaL_Reg functions[];
	};
}