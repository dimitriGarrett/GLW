#include "Mouse.h"
#include "../glfw/glfw3.h"

inline GLW::MouseState GLW::Mouse::getMouseButton(GLFWwindow* window, int button)
{
	return static_cast<MouseState>(glfwGetMouseButton(window, button));
}