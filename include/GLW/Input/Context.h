#pragma once

#include "../API.h"

#include <string_view>

struct GLFWwindow;

namespace GLW
{
	using GLFWglproc = void(*)(void);

	namespace Context
	{
		//Makes the context of the specified window current for the calling thread
		GLW_API void makeContextCurrent(GLFWwindow* window);
		
		//Returns the window whose context is current on the calling thread
		GLW_API GLFWwindow* getCurrentContext();

		//Sets the swap interval for the current context
		GLW_API void swapInterval(int interval);

		//Returns whether the specified extension is available
		GLW_API bool extensionSupported(std::string_view extension);

		//Returns the address of the specified function for the current context
		GLW_API GLFWglproc getProcAddress(std::string_view procname);
	}
}