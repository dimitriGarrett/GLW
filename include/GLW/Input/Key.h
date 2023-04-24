#pragma once

#include "../API.h"

#include <string_view>

struct GLFWwindow;

namespace GLW
{
	enum class KeyState : unsigned int
	{
		RELEASE = 0,
		PRESS = 1,
		REPEAT = 2
	};

	//Returns the layout-specific name of the specified printable key
	GLW_API std::string getKeyName(int key, int scancode);

	//Returns the platform-specific scancode of the specified key
	GLW_API int getKeyScancode(int key);

	//Returns the layout-specific name of the specified printable key
	GLW_API inline std::string getKeyName(int key)
	{
		return getKeyName(key, getKeyScancode(key));
	}

	//Returns the last reported state of a keyboard key for the specified window
	GLW_API KeyState getKey(GLFWwindow* window, int key);
}