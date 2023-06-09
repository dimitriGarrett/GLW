#include "InputMode.h"
#include "../glfw/glfw3.h"

inline void GLW::setInputMode(GLFWwindow* window, InputModeMode mode, InputModeValue value)
{
	glfwSetInputMode(window, static_cast<int>(mode), static_cast<int>(value));
}

inline GLW::InputModeValue GLW::getInputMode(GLFWwindow* window, InputModeMode mode)
{
	return static_cast<GLW::InputModeValue>(glfwGetInputMode(window, static_cast<int>(mode)));
}