#pragma once

#include "common/Lua.h"

namespace only2d
{
	class LuaTexture
	{
	public:
		static void openModule(lua_State *L);

	protected:
		static int32_t createTextureData(lua_State *L);

	private:
		static const luaL_Reg functions[];
	};
}