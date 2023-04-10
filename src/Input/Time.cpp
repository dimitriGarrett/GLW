#include "Time.h"
#include "../glfw/glfw3.h"

inline double GLW::Time::getTime()
{
	return glfwGetTime();
}

inline void GLW::Time::setTime(double time)
{
	glfwSetTime(time);
}

inline uint64_t GLW::Time::getTimerValue()
{
	return glfwGetTimerValue();
}

inline uint64_t GLW::Time::getTimerFrequency()
{
	return glfwGetTimerFrequency();
}
