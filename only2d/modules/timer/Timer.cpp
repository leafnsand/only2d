#include "Timer.h"
#include "common/Console.h"

namespace only2d
{
	Timer::Timer() :
		lastUpdate(std::chrono::system_clock::now()),
		count(0),
		fps(0),
		delta(0.0f),
		time(0.0f),
		lastUpdateFPS(0.0f)
	{
	}

	Timer::~Timer()
	{
	}

	float Timer::step()
	{
		auto now = std::chrono::system_clock::now();
		auto duration = now - lastUpdate;
		delta = std::chrono::duration_cast<std::chrono::duration<float>>(duration).count();
		time += delta;
		lastUpdate = now;
		++count;
		if (time - lastUpdateFPS > 1.0f)
		{
			fps = static_cast<int32_t>(count / (time - lastUpdateFPS));
			count = 0;
			lastUpdateFPS = time;
		}
		return delta;
	}

	float Timer::getTime() const
	{
		return time;
	}

	float Timer::getDelta() const
	{
		return delta;
	}

	int32_t Timer::getFPS() const
	{
		return fps;
	}
}
