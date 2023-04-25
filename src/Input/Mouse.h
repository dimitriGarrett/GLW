#pragma once

#include "../API.h"
#include "Codes.h"

struct GLFWwindow;

namespace GLW
{
	enum class MouseState : unsigned int
	{
		RELEASE = 0,
		PRESS = 1,
		REPEAT = 2
	};

	//Returns the last reported state of a mouse button for the specified window
	GLW_API MouseState getMouseButton(GLFWwindow* window, int button);

	static bool mouseState[MOUSE_BUTTON_LAST] = {};

	//CONVENIENCE - Function to test if a mouse button is pressed, with an optional parameter to ensure the button is pressed then released to trigger something
	static bool isMouseButtonPressed(GLFWwindow* window, int button, bool cannotBeHeld = false)
	{
		auto state = getMouseButton(window, button);
		bool isPressed = (state != MouseState::RELEASE);

		if (cannotBeHeld)
		{
			bool oldVal = mouseState[button];
			mouseState[button] = isPressed;

			if (oldVal == false)
			{
				return isPressed;
			}

			return false;
		}

		return isPressed;
	}
}