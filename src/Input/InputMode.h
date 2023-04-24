#pragma once

#include "../API.h"

struct GLFWwindow;

namespace GLW
{
	enum class InputModeMode : unsigned int
	{
		CURSOR = 0x00033001,
		STICKY_KEYS = 0x00033002,
		STICKY_MOUSE_BUTTONS = 0x00033003,
		LOCK_KEY_MODS = 0x00033004,
		RAW_MOUSE_MOTION = 0x00033005
	};

	enum class InputModeValue : unsigned int
	{
		FALSE = 0,
		TRUE = 1,
		CURSOR_NORMAL = 0x00034001,
		CURSOR_HIDDEN = 0x00034002,
		CURSOR_DISABLED = 0x00034003
	};

	//Sets an input option for the specified window
	GLW_API void setInputMode(GLFWwindow* window, InputModeMode mode, InputModeValue value);

	//Returns the value of an input option for the specified window
	GLW_API InputModeValue getInputMode(GLFWwindow* window, InputModeMode mode);
}