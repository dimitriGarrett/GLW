#include "Key.h"
#include "../glfw/glfw3.h"

inline std::string GLW::getKeyName(int key, int scancode)
{
	return glfwGetKeyName(key, scancode);
}

inline int GLW::getKeyScancode(int key)
{
	return glfwGetKeyScancode(key);
}

inline GLW::KeyState GLW::getKey(GLFWwindow* window, int key)
{
	return static_cast<KeyState>(glfwGetKey(window, key));
}
