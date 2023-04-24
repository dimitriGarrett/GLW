#pragma once

#include "../API.h"

struct GLFWwindow;

namespace GLW
{
	using keyCallback = void(*)(GLFWwindow*, int, int, int, int);
	using charCallback = void(*)(GLFWwindow*, unsigned int);
	using charModsCallback = void(*)(GLFWwindow*, unsigned int, int);
	using mouseButtonCallback = void(*)(GLFWwindow*, int, int, int);
	using cursorPosCallback = void(*)(GLFWwindow*, double, double);
	using cursorEnterCallback = void(*)(GLFWwindow*, int);
	using scrollCallback = void(*)(GLFWwindow*, double, double);
	using dropCallback = void(*)(GLFWwindow*, int, const char**);

	//Sets the key callback
	GLW_API keyCallback setKeyCallback(GLFWwindow* window, keyCallback callback);

	//Sets the Unicode character callback
	GLW_API charCallback setCharCallback(GLFWwindow* window, charCallback callback);

	//Sets the Unicode character with modifiers callback
	GLW_API charModsCallback setCharModsCallback(GLFWwindow* window, charModsCallback callback);

	//Sets the mouse button callback
	GLW_API mouseButtonCallback setMouseButtonCallback(GLFWwindow* window, mouseButtonCallback callback);

	//Sets the cursor position callback
	GLW_API cursorPosCallback setCursorPosCallback(GLFWwindow* window, cursorPosCallback callback);

	//Sets the cursor enter/leave callback
	GLW_API cursorEnterCallback setCursorEnterCallback(GLFWwindow* window, cursorEnterCallback callback);

	//Sets the scroll callback
	GLW_API scrollCallback setScrollCallback(GLFWwindow* window, scrollCallback callback);

	//Sets the path drop callback
	GLW_API dropCallback setDropCallback(GLFWwindow* window, dropCallback callback);
}