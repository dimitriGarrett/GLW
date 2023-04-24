#include "Callback.h"
#include "../glfw/glfw3.h"

inline GLW::keyCallback GLW::setKeyCallback(GLFWwindow* window, keyCallback callback)
{
	return glfwSetKeyCallback(window, callback);
}

inline GLW::charCallback GLW::setCharCallback(GLFWwindow* window, charCallback callback)
{
	return glfwSetCharCallback(window, callback);
}

inline GLW::charModsCallback GLW::setCharModsCallback(GLFWwindow* window, charModsCallback callback)
{
	return glfwSetCharModsCallback(window, callback);
}

inline GLW::mouseButtonCallback GLW::setMouseButtonCallback(GLFWwindow* window, mouseButtonCallback callback)
{
	return glfwSetMouseButtonCallback(window, callback);
}

inline GLW::cursorPosCallback GLW::setCursorPosCallback(GLFWwindow* window, cursorPosCallback callback)
{
	return glfwSetCursorPosCallback(window, callback);
}

inline GLW::cursorEnterCallback GLW::setCursorEnterCallback(GLFWwindow* window, cursorEnterCallback callback)
{
	return glfwSetCursorEnterCallback(window, callback);
}

inline GLW::scrollCallback GLW::setScrollCallback(GLFWwindow* window, scrollCallback callback)
{
	return glfwSetScrollCallback(window, callback);
}

inline GLW::dropCallback GLW::setDropCallback(GLFWwindow* window, dropCallback callback)
{
	return glfwSetDropCallback(window, callback);
}
