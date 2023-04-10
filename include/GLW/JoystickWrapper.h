#pragma once

#include "Input/Joystick.h"

namespace GLW
{
	struct JoystickWrapper
	{
		JoystickWrapper(int id)
			: jid(id)
		{
		}

		inline bool present() const
		{
			return Joystick::joystickPresent(jid);
		}

		inline const float* getAxes(int* count) const
		{
			return Joystick::getJoystickAxes(jid, count);
		}

		inline std::vector<float> getAxes() const
		{
			return Joystick::getJoystickAxes(jid);
		}

		inline const unsigned char* getButtons(int* count) const
		{
			return Joystick::getJoystickButtons(jid, count);
		}

		inline std::vector<unsigned char> getButtons() const
		{
			return Joystick::getJoystickButtons(jid);
		}

		inline const unsigned char* getHats(int* count) const
		{
			return Joystick::getJoystickHats(jid, count);
		}

		inline std::vector<unsigned char> getHats() const
		{
			return Joystick::getJoystickHats(jid);
		}

		inline std::string getName() const
		{
			return Joystick::getJoystickName(jid);
		}

		inline std::string getGUID() const
		{
			return Joystick::getJoystickGUID(jid);
		}

		inline void setUserPointer(void* data) const
		{
			Joystick::setJoystickUserPointer(jid, data);
		}

		inline void* getUserPointer() const
		{
			return Joystick::getJoystickUserPointer(jid);
		}

		inline bool isGamepad() const
		{
			return Joystick::joystickIsGamepad(jid);
		}

		inline static void setJoystickCallback(joystickCallback callback)
		{
			Joystick::setJoystickCallback(callback);
		}

		inline static int updateGamepadMappings(std::string_view string)
		{
			Joystick::updateGamepadMappings(string);
		}

		inline std::string getGamepadName() const
		{
			return Joystick::getGamepadName(jid);
		}

		inline int getGamepadState(GLFWgamepadstate* state) const
		{
			return Joystick::getGamepadState(jid, state);
		}

		int jid;
	};
}