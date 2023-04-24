#pragma once

#include "../API.h"

#include <string_view>
#include <vector>

struct GLFWgamepadstate;

namespace GLW
{
	using joystickCallback = void(*)(int jid, int event);

	//Returns whether the specified joystick is present
	GLW_API bool joystickPresent(int jid);

	//Returns the values of all axes of the specified joystick
	GLW_API const float* getJoystickAxes(int jid, int* count);
	//Returns the values of all axes of the specified joystick
	static std::vector<float> getJoystickAxes(int jid)
	{
		std::vector<float> temp;
		int count;

		const float* temp2 = getJoystickAxes(jid, &count);
		temp.resize(count);
		memcpy_s(&temp.front(), count, temp2, count);

		return temp;
	}

	//Returns the state of all buttons of the specified joystick
	GLW_API const unsigned char* getJoystickButtons(int jid, int* count);
	//Returns the state of all buttons of the specified joystick
	static std::vector<unsigned char> getJoystickButtons(int jid)
	{
		std::vector<unsigned char> temp;
		int count;

		const unsigned char* temp2 = getJoystickButtons(jid, &count);
		temp.resize(count);
		memcpy_s(&temp.front(), count, temp2, count);

		return temp;
	}

	//Returns the state of all hats of the specified joystick
	GLW_API const unsigned char* getJoystickHats(int jid, int* count);
	//Returns the state of all hats of the specified joystick
	static std::vector<unsigned char> getJoystickHats(int jid)
	{
		std::vector<unsigned char> temp;
		int count;

		const unsigned char* temp2 = getJoystickHats(jid, &count);
		temp.resize(count);
		memcpy_s(&temp.front(), count, temp2, count);

		return temp;
	}

	//Returns the name of the specified joystick
	GLW_API std::string getJoystickName(int jid);

	//Returns the SDL compatible GUID of the specified joystick
	GLW_API std::string getJoystickGUID(int jid);

	//Sets the user pointer of the specified joystick
	GLW_API void setJoystickUserPointer(int jid, void* data);

	//Returns the user pointer of the specified joystick
	GLW_API void* getJoystickUserPointer(int jid);

	//Returns whether the specified joystick has a gamepad mapping
	GLW_API bool joystickIsGamepad(int jid);

	//Sets the joystick configuration callback
	GLW_API void setJoystickCallback(joystickCallback callback);

	//Adds the specified SDL_GameControllerDB gamepad mappings
	GLW_API int updateGamepadMappings(std::string_view string);

	//Returns the human-readable gamepad name for the specified joystick
	GLW_API std::string getGamepadName(int jid);

	//Retrieves the state of the specified joystick remapped as a gamepad
	GLW_API int getGamepadState(int jid, GLFWgamepadstate* state);
}