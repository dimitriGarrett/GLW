#include "Monitor.h"
#include "glfw/glfw3.h"

inline GLFWmonitor** GLW::getMonitors(int* count)
{
	return glfwGetMonitors(count);
}

inline std::vector<GLFWmonitor*> GLW::getMonitors()
{
	std::vector<GLFWmonitor*> temp;
	int count;

	GLFWmonitor** temp2 = getMonitors(&count);
	temp.resize(count);
	memcpy_s(&temp.front(), count, temp2, count);

	return temp;
}

inline GLFWmonitor* GLW::getPrimaryMonitor()
{
	return glfwGetPrimaryMonitor();
}

inline void GLW::getMonitorPos(GLFWmonitor* monitor, int* xpos, int* ypos)
{
	glfwGetMonitorPos(monitor, xpos, ypos);
}

inline void GLW::getMonitorWorkarea(GLFWmonitor* monitor, int* xpos, int* ypos, int* width, int* height)
{
	glfwGetMonitorWorkarea(monitor, xpos, ypos, width, height);
}

inline void GLW::getMonitorPhysicalSize(GLFWmonitor* monitor, int* widthMM, int* heightMM)
{
	glfwGetMonitorPhysicalSize(monitor, widthMM, heightMM);
}

inline void GLW::getMonitorContentScale(GLFWmonitor* monitor, float* xscale, float* yscale)
{
	glfwGetMonitorContentScale(monitor, xscale, yscale);
}

inline std::string GLW::getMonitorName(GLFWmonitor* monitor)
{
	return glfwGetMonitorName(monitor);
}

inline void GLW::setMonitorUserPointer(GLFWmonitor* monitor, void* pointer)
{
	glfwSetMonitorUserPointer(monitor, pointer);
}

inline void* GLW::getMonitorUserPointer(GLFWmonitor* monitor)
{
	return glfwGetMonitorUserPointer(monitor);
}

inline GLW::monitorCallback GLW::setMonitorCallback(monitorCallback callback)
{
	return glfwSetMonitorCallback(callback);
}

inline const GLFWvidmode* GLW::getVideoModes(GLFWmonitor* monitor, int* count)
{
	return glfwGetVideoModes(monitor, count);
}

inline const GLFWvidmode* GLW::getVideoMode(GLFWmonitor* monitor)
{
	return glfwGetVideoMode(monitor);
}

inline void GLW::setGamma(GLFWmonitor* monitor, float gamma)
{
	glfwSetGamma(monitor, gamma);
}

inline const GLFWgammaramp* GLW::getGammaRamp(GLFWmonitor* monitor)
{
	return glfwGetGammaRamp(monitor);
}

inline void GLW::setGammaRamp(GLFWmonitor* monitor, const GLFWgammaramp* ramp)
{
	glfwSetGammaRamp(monitor, ramp);
}