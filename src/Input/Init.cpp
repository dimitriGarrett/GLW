#include "Init.h"
#include "../glfw/glfw3.h"

inline bool GLW::init()
{
	return glfwInit();
}

inline void GLW::terminate()
{
	glfwTerminate();
}

inline void GLW::initHint(InitHint hint, int value)
{
	glfwInitHint(static_cast<int>(hint), value);
}

inline void GLW::getVersion(int* major, int* minor, int* rev)
{
	glfwGetVersion(major, minor, rev);
}

inline std::pair<std::pair<int, int>, int> GLW::getVersion()
{
	int major;
	int minor;
	int rev;

	getVersion(&major, &minor, &rev);

	return { { major, minor }, rev };
}

inline std::string_view GLW::getVersionString()
{
	return glfwGetVersionString();
}

inline GLW::ErrorCode GLW::getError(const char** description)
{
	return static_cast<ErrorCode>(glfwGetError(description));
}

inline std::pair<GLW::ErrorCode, std::string> GLW::getError()
{
	const char* temp;
	ErrorCode tempError = getError(&temp);

	return { tempError, temp };
}

inline GLW::errorCallback GLW::setErrorCallback(errorCallback callback)
{
	return glfwSetErrorCallback(callback);
}