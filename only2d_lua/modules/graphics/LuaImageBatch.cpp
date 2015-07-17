//
// Created by leafnsand on 2015/7/16.
//

#include "LuaImageBatch.h"

#include "modules/graphics/ImageBatch.h"

namespace only2d
{
	const luaL_Reg LuaImageBatch::functions[] =
	{
		{ "addImage", addImage },
		{ "clear", clear },
		{ "draw", draw },
		{ nullptr, nullptr }
	};

	void LuaImageBatch::openType(lua_State *L)
	{
		Lua::beginType(L, LuaType::ImageBatch);
		Lua::pushFunctions(L, functions);
		Lua::finishType(L, LuaType::Drawable);
	}

	int32_t LuaImageBatch::addImage(lua_State *L)
	{
		auto imageBatch = Lua::getObject<ImageBatch>(L, 1, LuaType::ImageBatch);
		auto image = Lua::getObject<Image>(L, 2, LuaType::Image);
		imageBatch->addImage(image);
		return 0;
	}

	int32_t LuaImageBatch::clear(lua_State *L)
	{
		auto imageBatch = Lua::getObject<ImageBatch>(L, 1, LuaType::ImageBatch);
		imageBatch->clear();
		return 0;
	}

	int32_t LuaImageBatch::draw(lua_State *L)
	{
		auto imageBatch = Lua::getObject<ImageBatch>(L, 1, LuaType::ImageBatch);
		imageBatch->draw();
		return 0;
	}
}
