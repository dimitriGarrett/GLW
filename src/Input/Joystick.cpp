#include "Joystick.h"
#include "../glfw/glfw3.h"

inline bool GLW::Joystick::joystickPresent(int jid)
{
	return glfwJoystickPresent(jid);
}

inline const float* GLW::Joystick::getJoystickAxes(int jid, int* count)
{
	return glfwGetJoystickAxes(jid, count);
}

inline const unsigned char* GLW::Joystick::getJoystickButtons(int jid, int* count)
{
	return glfwGetJoystickButtons(jid, count);
}

inline const unsigned char* GLW::Joystick::getJoystickHats(int jid, int* count)
{
	return glfwGetJoystickHats(jid, count);
}

inline std::string GLW::Joystick::getJoystickName(int jid)
{
	return glfwGetJoystickName(jid);
}

inline std::string GLW::Joystick::getJoystickGUID(int jid)
{
	return glfwGetJoystickGUID(jid);
}

inline void GLW::Joystick::setJoystickUserPointer(int jid, void* data)
{
	glfwSetJoystickUserPointer(jid, data);
}

inline void* GLW::Joystick::getJoystickUserPointer(int jid)
{
	return glfwGetJoystickUserPointer(jid);
}

inline bool GLW::Joystick::joystickIsGamepad(int jid)
{
	return glfwJoystickIsGamepad(jid);
}

inline void GLW::Joystick::setJoystickCallback(joystickCallback callback)
{
	glfwSetJoystickCallback(callback);
}

inline int GLW::Joystick::updateGamepadMappings(std::string_view string)
{
	return glfwUpdateGamepadMappings(string.data());
}

inline std::string GLW::Joystick::getGamepadName(int jid)
{
	return glfwGetGamepadName(jid);
}

inline int GLW::Joystick::getGamepadState(int jid, GLFWgamepadstate* state)
{
	return glfwGetGamepadState(jid, state);
}