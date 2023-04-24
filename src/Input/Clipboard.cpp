#include "Clipboard.h"
#include "../glfw/glfw3.h"

inline void GLW::setClipboardString(GLFWwindow* window, std::string_view str)
{
	glfwSetClipboardString(window, str.data());
}

inline std::string GLW::getClipboardString(GLFWwindow* window)
{
	return glfwGetClipboardString(window);
}