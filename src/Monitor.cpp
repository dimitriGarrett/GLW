#include "Monitor.h"
#include "glfw/glfw3.h"

inline GLFWmonitor** GLW::Monitor::getMonitors(int* count)
{
	return glfwGetMonitors(count);
}

inline std::vector<GLFWmonitor*> GLW::Monitor::getMonitors()
{
	std::vector<GLFWmonitor*> temp;
	int count;

	GLFWmonitor** temp2 = getMonitors(&count);
	temp.resize(count);
	memcpy_s(&temp.front(), count, temp2, count);

	return temp;
}

inline GLFWmonitor* GLW::Monitor::getPrimaryMonitor()
{
	return glfwGetPrimaryMonitor();
}

inline void GLW::Monitor::getMonitorPos(GLFWmonitor* monitor, int* xpos, int* ypos)
{
	glfwGetMonitorPos(monitor, xpos, ypos);
}

inline void GLW::Monitor::getMonitorWorkarea(GLFWmonitor* monitor, int* xpos, int* ypos, int* width, int* height)
{
	glfwGetMonitorWorkarea(monitor, xpos, ypos, width, height);
}

inline void GLW::Monitor::getMonitorPhysicalSize(GLFWmonitor* monitor, int* widthMM, int* heightMM)
{
	glfwGetMonitorPhysicalSize(monitor, widthMM, heightMM);
}

inline void GLW::Monitor::getMonitorContentScale(GLFWmonitor* monitor, float* xscale, float* yscale)
{
	glfwGetMonitorContentScale(monitor, xscale, yscale);
}

inline std::string GLW::Monitor::getMonitorName(GLFWmonitor* monitor)
{
	return glfwGetMonitorName(monitor);
}

inline void GLW::Monitor::setMonitorUserPointer(GLFWmonitor* monitor, void* pointer)
{
	glfwSetMonitorUserPointer(monitor, pointer);
}

inline void* GLW::Monitor::getMonitorUserPointer(GLFWmonitor* monitor)
{
	return glfwGetMonitorUserPointer(monitor);
}

inline GLW::monitorCallback GLW::Monitor::setMonitorCallback(monitorCallback callback)
{
	return glfwSetMonitorCallback(callback);
}

inline const GLFWvidmode* GLW::Monitor::getVideoModes(GLFWmonitor* monitor, int* count)
{
	return glfwGetVideoModes(monitor, count);
}

inline const GLFWvidmode* GLW::Monitor::getVideoMode(GLFWmonitor* monitor)
{
	return glfwGetVideoMode(monitor);
}

inline void GLW::Monitor::setGamma(GLFWmonitor* monitor, float gamma)
{
	glfwSetGamma(monitor, gamma);
}

inline const GLFWgammaramp* GLW::Monitor::getGammaRamp(GLFWmonitor* monitor)
{
	return glfwGetGammaRamp(monitor);
}

inline void GLW::Monitor::setGammaRamp(GLFWmonitor* monitor, const GLFWgammaramp* ramp)
{
	glfwSetGammaRamp(monitor, ramp);
}