#include "Init.h"
#include "../glfw/glfw3.h"

inline bool GLW::Init::init()
{
	return glfwInit();
}

inline void GLW::Init::terminate()
{
	glfwTerminate();
}

inline void GLW::Init::initHint(InitHint hint, int value)
{
	glfwInitHint(static_cast<int>(hint), value);
}

inline void GLW::Init::getVersion(int* major, int* minor, int* rev)
{
	glfwGetVersion(major, minor, rev);
}

inline std::pair<std::pair<int, int>, int> GLW::Init::getVersion()
{
	int major;
	int minor;
	int rev;

	getVersion(&major, &minor, &rev);

	return { { major, minor }, rev };
}

inline std::string_view GLW::Init::getVersionString()
{
	return glfwGetVersionString();
}

inline GLW::ErrorCode GLW::Init::getError(const char** description)
{
	return static_cast<ErrorCode>(glfwGetError(description));
}

inline std::pair<GLW::ErrorCode, std::string> GLW::Init::getError()
{
	const char* temp;
	ErrorCode tempError = getError(&temp);

	return { tempError, temp };
}

inline GLW::errorCallback GLW::Init::setErrorCallback(errorCallback callback)
{
	return glfwSetErrorCallback(callback);
}