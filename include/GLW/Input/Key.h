#pragma once

#include "../API.h"
#include "Codes.h"

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

	static bool status[KEY_MENU] = {};

	//CONVENIENCE - boolean value that determines if a key is held or not, with an optional parameter to ensure the key is pressed then released to trigger something
	static bool isKeyPressed(GLFWwindow* window, int keycode, bool cannotBeHeld = false)
	{
		auto state = getKey(window, keycode);
		bool isPressed = (state != KeyState::RELEASE);

		if (cannotBeHeld)
		{
			bool oldVal = status[keycode];
			status[keycode] = isPressed;

			if (oldVal == false)
			{
				return isPressed;
			}

			return false;
		}

		return isPressed;
	}

	//CONVENIENCE - boolean value that determines if any key within a range is pressed
	static bool anyKeyPressed(GLFWwindow* window, int startKeycode, int endKeycode, bool cannotBeHeld = false)
	{
		for (int i = startKeycode; i <= endKeycode; ++i)
			if (isKeyPressed(window, i, cannotBeHeld))
				return true;

		return false;
	}
}