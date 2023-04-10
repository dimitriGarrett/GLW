#include "Clipboard.h"
#include "../glfw/glfw3.h"

inline void GLW::Clipboard::setClipboardString(GLFWwindow* window, std::string_view str)
{
	glfwSetClipboardString(window, str.data());
}

inline std::string GLW::Clipboard::getClipboardString(GLFWwindow* window)
{
	return glfwGetClipboardString(window);

	
}