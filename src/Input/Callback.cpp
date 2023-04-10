#include "Callback.h"
#include "../glfw/glfw3.h"

inline GLW::keyCallback GLW::Callback::setKeyCallback(GLFWwindow* window, keyCallback callback)
{
	return glfwSetKeyCallback(window, callback);
}

inline GLW::charCallback GLW::Callback::setCharCallback(GLFWwindow* window, charCallback callback)
{
	return glfwSetCharCallback(window, callback);
}

inline GLW::charModsCallback GLW::Callback::setCharModsCallback(GLFWwindow* window, charModsCallback callback)
{
	return glfwSetCharModsCallback(window, callback);
}

inline GLW::mouseButtonCallback GLW::Callback::setMouseButtonCallback(GLFWwindow* window, mouseButtonCallback callback)
{
	return glfwSetMouseButtonCallback(window, callback);
}

inline GLW::cursorPosCallback GLW::Callback::setCursorPosCallback(GLFWwindow* window, cursorPosCallback callback)
{
	return glfwSetCursorPosCallback(window, callback);
}

inline GLW::cursorEnterCallback GLW::Callback::setCursorEnterCallback(GLFWwindow* window, cursorEnterCallback callback)
{
	return glfwSetCursorEnterCallback(window, callback);
}

inline GLW::scrollCallback GLW::Callback::setScrollCallback(GLFWwindow* window, scrollCallback callback)
{
	return glfwSetScrollCallback(window, callback);
}

inline GLW::dropCallback GLW::Callback::setDropCallback(GLFWwindow* window, dropCallback callback)
{
	return glfwSetDropCallback(window, callback);
}
