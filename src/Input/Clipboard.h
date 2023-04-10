#pragma once

#include "../API.h"

#include <string_view>

struct GLFWwindow;

namespace GLW
{
	namespace Clipboard
	{
		//Sets the clipboard to the specified string
		GLW_API void setClipboardString(GLFWwindow* window, std::string_view str);
		
		//Returns the contents of the clipboard as a string
		GLW_API std::string getClipboardString(GLFWwindow* window);
	}
}