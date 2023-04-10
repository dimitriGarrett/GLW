#pragma once

#include "../API.h"
#include "ErrorCodes.h"

#include <string_view>

namespace GLW
{
	enum class InitHint
	{
		JOYSTICK_HAT_BUTTONS = 0x00050001,
#if __APPLE__
		COCOA_CHDIR_RESOURCES = 0x00051001,
		COCOA_MENUBAR = 0x00051002,
#endif
	};

	using errorCallback = void(*)(int error_code, const char* description);

	namespace Init
	{
		//Initializes the GLFW library
		GLW_API bool init();

		//Terminates the GLFW library
		GLW_API void terminate();

		//Sets the specified init hint to the desired value
		GLW_API void initHint(InitHint hint, int value);

		//Retrieves the version of the GLFW library
		GLW_API void getVersion(int* major, int* minor, int* rev);
		//Retrieves the version of the GLFW library
		GLW_API std::pair<std::pair<int, int>, int> getVersion();

		//Returns a string describing the compile-time configuration
		GLW_API std::string_view getVersionString();

		//Returns and clears the last error for the calling thread
		GLW_API ErrorCode getError(const char** description);
		//Returns and clears the last error for the calling thread
		GLW_API std::pair<ErrorCode, std::string> getError();

		//Sets the error callback
		GLW_API errorCallback setErrorCallback(errorCallback callback);
	}
}