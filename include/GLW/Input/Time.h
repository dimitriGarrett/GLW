#pragma once

#include "../API.h"
#include <cstdint>

namespace GLW
{
	namespace Time
	{
		//Returns the GLFW time
		GLW_API double getTime();

		//Sets the GLFW time
		GLW_API void setTime(double time);

		//Returns the current value of the raw timer
		GLW_API uint64_t getTimerValue();

		//Returns the frequency, in Hz, of the raw timer
		GLW_API uint64_t getTimerFrequency();
	}
}