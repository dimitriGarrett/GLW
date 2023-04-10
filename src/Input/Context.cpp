#include "Context.h"
#include "../glfw/glfw3.h"

inline void GLW::Context::makeContextCurrent(GLFWwindow* window)
{
	glfwMakeContextCurrent(window);
}

inline GLFWwindow* GLW::Context::getCurrentContext()
{
	return glfwGetCurrentContext();
}

inline void GLW::Context::swapInterval(int interval)
{
	glfwSwapInterval(interval);
}

inline bool GLW::Context::extensionSupported(std::string_view extension)
{
	return static_cast<bool>(glfwExtensionSupported(extension.data()));
}

inline GLFWglproc GLW::Context::getProcAddress(std::string_view procname)
{
	return glfwGetProcAddress(procname.data());
}