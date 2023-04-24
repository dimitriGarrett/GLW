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
}