#include "Time.h"
#include "../glfw/glfw3.h"

inline double GLW::getTime()
{
	return glfwGetTime();
}

inline void GLW::setTime(double time)
{
	glfwSetTime(time);
}

inline uint64_t GLW::getTimerValue()
{
	return glfwGetTimerValue();
}

inline uint64_t GLW::getTimerFrequency()
{
	return glfwGetTimerFrequency();
}
