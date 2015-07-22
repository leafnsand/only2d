#include "LuaGraphics.h"
#include "LuaBlendMode.h"
#include "LuaDrawable.h"
#include "LuaImage.h"
#include "LuaImageBatch.h"
#include "LuaImageData.h"
#include "LuaImageDataFilterMode.h"
#include "LuaImageDataWrapMode.h"
#include "LuaQuad.h"
#include "LuaQuadBatch.h"
#include "LuaShader.h"

#include "common/Module.h"

#include "modules/graphics/Graphics.h"

namespace only2d
{
	const luaL_Reg LuaGraphics::functions[] =
	{
		{ "createShader", createShader },
		{ "createImageData", createImageData },
		{ "createImage", createImage },
		{ "createImageBatch", createImageBatch },
		{ "createQuad", createQuad },
		{ "createQuadBatch", createQuadBatch},
		{ "getBackgroundColor", getBackgroundColor },
		{ "setBackgroundColor", setBackgroundColor },
		{ "getDrawCalls", getDrawCalls },
		{ nullptr, nullptr }
	};

	void LuaGraphics::openModule(lua_State *L)
	{
		Lua::beginModule(L, LuaModule::Graphics);
		Lua::pushFunctions(L, functions);
		LuaBlendMode::openEnum(L);
		LuaImageDataFilterMode::openEnum(L);
		LuaImageDataWrapMode::openEnum(L);
		Lua::finishModule(L, LuaModule::Graphics);
		LuaDrawable::openType(L);
		LuaQuad::openType(L);
		LuaQuadBatch::openType(L);
		LuaImage::openType(L);
		LuaImageBatch::openType(L);
		LuaImageData::openType(L);
		LuaShader::openType(L);
	}

	int32_t LuaGraphics::createShader(lua_State *L)
	{
		auto graphics = Module::getInstance<Graphics>(ModuleType::GRAPHICS);
		auto vertex = Lua::getString(L, 1);
		auto fragment = Lua::getString(L, 2);
		auto shader = graphics->createShader(vertex, fragment);
		Lua::pushObject(L, LuaType::Shader, shader);
		return 1;
	}

	int32_t LuaGraphics::createImageData(lua_State *L)
	{
		auto graphics = Module::getInstance<Graphics>(ModuleType::GRAPHICS);
		auto width = static_cast<int32_t>(Lua::getInteger(L, 1));
		auto height = static_cast<int32_t>(Lua::getInteger(L, 2));
		auto data = Lua::getObject<Data>(L, 3, LuaType::Data);
		auto imageData = graphics->createImageData(width, height, data);
		Lua::pushObject(L, LuaType::ImageData, imageData);
		return 1;
	}

	int32_t LuaGraphics::createImage(lua_State *L)
	{
		auto graphics = Module::getInstance<Graphics>(ModuleType::GRAPHICS);
		auto imageData = Lua::getObject<ImageData>(L, 1, LuaType::ImageData);
		auto image = graphics->createImage(imageData);
		Lua::pushObject(L, LuaType::Image, image);
		return 1;
	}

	int32_t LuaGraphics::createImageBatch(lua_State * L)
	{
		auto graphics = Module::getInstance<Graphics>(ModuleType::GRAPHICS);
		auto imageBatch = graphics->createImageBatch();
		Lua::pushObject(L, LuaType::QuadBatch, imageBatch);
		return 1;
	}

	int32_t LuaGraphics::createQuad(lua_State * L)
	{
		auto graphics = Module::getInstance<Graphics>(ModuleType::GRAPHICS);
		auto width = static_cast<int32_t>(Lua::getInteger(L, 1));
		auto height = static_cast<int32_t>(Lua::getInteger(L, 2));
		auto quad = graphics->createQuad(width, height);
		Lua::pushObject(L, LuaType::Image, quad);
		return 1;
	}

	int32_t LuaGraphics::createQuadBatch(lua_State *L)
	{
		auto graphics = Module::getInstance<Graphics>(ModuleType::GRAPHICS);
		auto quadBatch = graphics->createQuadBatch();
		Lua::pushObject(L, LuaType::QuadBatch, quadBatch);
		return 1;
	}

	int32_t LuaGraphics::getBackgroundColor(lua_State *L)
	{
		auto graphics = Module::getInstance<Graphics>(ModuleType::GRAPHICS);
		auto color = graphics->getBackgroundColor();
		Lua::pushInteger(L, colorToInt(color));
		return 1;
	}

	int32_t LuaGraphics::setBackgroundColor(lua_State *L)
	{
		auto graphics = Module::getInstance<Graphics>(ModuleType::GRAPHICS);
		auto color = static_cast<int32_t>(Lua::getInteger(L, 1));
		graphics->setBackgroundColor(intToColor(color));
		return 0;
	}

    int32_t LuaGraphics::getDrawCalls(lua_State *L)
    {
	    auto graphics = Module::getInstance<Graphics>(ModuleType::GRAPHICS);
	    Lua::pushInteger(L, graphics->getOpenGL()->getDrawCalls());
	    return 1;
    }
}
