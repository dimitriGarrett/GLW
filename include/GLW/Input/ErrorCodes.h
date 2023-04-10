#pragma once

#ifdef _WIN32
	#undef NO_ERROR
#endif

namespace GLW
{
	enum class ErrorCode : unsigned int
	{
		NO_ERROR = 0,
		NOT_INITIALIZED = 0x00010001,
		NO_CURRENT_CONTEXT = 0x00010002,
		INVALID_ENUM = 0x00010003,
		INVALID_VALUE = 0x00010004,

		OUT_OF_MEMORY = 0x00010005,
		API_UNAVAILABLE = 0x00010006,
		VERSION_UNAVAILABLE = 0x00010007,
		PLATFORM_ERROR = 0x00010008,
		FORMAT_UNAVAILABLE = 0x00010009,
		NO_WINDOW_CONTEXT  = 0x0001000A
	};
}