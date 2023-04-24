#include "Context.h"
#include "../glfw/glfw3.h"

inline void GLW::makeContextCurrent(GLFWwindow* window)
{
	glfwMakeContextCurrent(window);
}

inline GLFWwindow* GLW::getCurrentContext()
{
	return glfwGetCurrentContext();
}

inline void GLW::swapInterval(int interval)
{
	glfwSwapInterval(interval);
}

inline bool GLW::extensionSupported(std::string_view extension)
{
	return static_cast<bool>(glfwExtensionSupported(extension.data()));
}

inline GLFWglproc GLW::getProcAddress(std::string_view procname)
{
	return glfwGetProcAddress(procname.data());
}