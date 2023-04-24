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
			return joystickPresent(jid);
		}

		inline const float* getAxes(int* count) const
		{
			return getJoystickAxes(jid, count);
		}

		inline std::vector<float> getAxes() const
		{
			return getJoystickAxes(jid);
		}

		inline const unsigned char* getButtons(int* count) const
		{
			return getJoystickButtons(jid, count);
		}

		inline std::vector<unsigned char> getButtons() const
		{
			return getJoystickButtons(jid);
		}

		inline const unsigned char* getHats(int* count) const
		{
			return getJoystickHats(jid, count);
		}

		inline std::vector<unsigned char> getHats() const
		{
			return getJoystickHats(jid);
		}

		inline std::string getName() const
		{
			return getJoystickName(jid);
		}

		inline std::string getGUID() const
		{
			return getJoystickGUID(jid);
		}

		inline void setUserPointer(void* data) const
		{
			setJoystickUserPointer(jid, data);
		}

		inline void* getUserPointer() const
		{
			return getJoystickUserPointer(jid);
		}

		inline bool isGamepad() const
		{
			return joystickIsGamepad(jid);
		}

		inline static void setJoystickCallback(joystickCallback callback)
		{
			setJoystickCallback(callback);
		}

		inline static int updateGamepadMappings(std::string_view string)
		{
			updateGamepadMappings(string);
		}

		inline std::string getGamepadName() const
		{
			return GLW::getGamepadName(jid);
		}

		inline int getGamepadState(GLFWgamepadstate* state) const
		{
			return GLW::getGamepadState(jid, state);
		}

		int jid;
	};
}