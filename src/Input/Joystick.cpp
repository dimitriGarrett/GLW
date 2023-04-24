#include "Joystick.h"
#include "../glfw/glfw3.h"

inline bool GLW::joystickPresent(int jid)
{
	return glfwJoystickPresent(jid);
}

inline const float* GLW::getJoystickAxes(int jid, int* count)
{
	return glfwGetJoystickAxes(jid, count);
}

inline const unsigned char* GLW::getJoystickButtons(int jid, int* count)
{
	return glfwGetJoystickButtons(jid, count);
}

inline const unsigned char* GLW::getJoystickHats(int jid, int* count)
{
	return glfwGetJoystickHats(jid, count);
}

inline std::string GLW::getJoystickName(int jid)
{
	return glfwGetJoystickName(jid);
}

inline std::string GLW::getJoystickGUID(int jid)
{
	return glfwGetJoystickGUID(jid);
}

inline void GLW::setJoystickUserPointer(int jid, void* data)
{
	glfwSetJoystickUserPointer(jid, data);
}

inline void* GLW::getJoystickUserPointer(int jid)
{
	return glfwGetJoystickUserPointer(jid);
}

inline bool GLW::joystickIsGamepad(int jid)
{
	return glfwJoystickIsGamepad(jid);
}

inline void GLW::setJoystickCallback(joystickCallback callback)
{
	glfwSetJoystickCallback(callback);
}

inline int GLW::updateGamepadMappings(std::string_view string)
{
	return glfwUpdateGamepadMappings(string.data());
}

inline std::string GLW::getGamepadName(int jid)
{
	return glfwGetGamepadName(jid);
}

inline int GLW::getGamepadState(int jid, GLFWgamepadstate* state)
{
	return glfwGetGamepadState(jid, state);
}