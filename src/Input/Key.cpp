#include "Key.h"
#include "../glfw/glfw3.h"

inline std::string GLW::Key::getKeyName(int key, int scancode)
{
	return glfwGetKeyName(key, scancode);
}

inline int GLW::Key::getKeyScancode(int key)
{
	return glfwGetKeyScancode(key);
}

inline GLW::KeyState GLW::Key::getKey(GLFWwindow* window, int key)
{
	return static_cast<KeyState>(glfwGetKey(window, key));
}
