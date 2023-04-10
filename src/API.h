#pragma once

#ifdef _WIN32
	#ifdef GLW_EXPORT
		#define GLW_API __declspec(dllexport)
	#else
		#define GLW_API __declspec(dllimport)
	#endif
#else
	#define GLW_API extern
#endif