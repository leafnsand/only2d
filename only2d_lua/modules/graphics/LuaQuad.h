//
// Created by leafnsand on 2015/7/21.
//

#pragma once

#include "common/Lua.h"

namespace only2d
{
	class LuaQuad
	{
	public:
		static void openType(lua_State *L);

	protected:
		static int32_t draw(lua_State *L);

		static int32_t getWidth(lua_State *L);

		static int32_t setWidth(lua_State *L);

		static int32_t getHeight(lua_State *L);

		static int32_t setHeight(lua_State *L);

	private:
		static const luaL_Reg functions[];
	};
}