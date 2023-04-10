#pragma once

#include "API.h"
#include "Vector.h"

#include <vector>
#include <string>

struct GLFWmonitor;
struct GLFWvidmode;
struct GLFWgammaramp;

namespace GLW
{
	using monitorCallback = void(*)(GLFWmonitor*, int);

	namespace Monitor
	{
		//Returns the currently connected monitors
		GLW_API GLFWmonitor** getMonitors(int* count);
		//Returns the currently connected monitors
		GLW_API std::vector<GLFWmonitor*> getMonitors();

		//Returns the primary monitor
		GLW_API GLFWmonitor* getPrimaryMonitor();

		//Returns the position of the monitor's viewport on the virtual screen
		GLW_API void getMonitorPos(GLFWmonitor* monitor, int* xpos, int* ypos);
		//Returns the position of the monitor's viewport on the virtual screen
		static ivec2 getMonitorPos(GLFWmonitor* monitor)
		{
			ivec2 temp;
			getMonitorPos(monitor, &temp.x, &temp.y);
			return temp;
		}

		//Retrieves the work area of the monitor
		GLW_API void getMonitorWorkarea(GLFWmonitor* monitor, int* xpos, int* ypos, int* width, int* height);
		//Retrieves the work area of the monitor
		static ivec4 getMonitorWorkarea(GLFWmonitor* monitor)
		{
			ivec4 temp;
			getMonitorWorkarea(monitor, &temp.x, &temp.y, &temp.z, &temp.w);
			return temp;
		}

		//Returns the physical size of the monitor
		GLW_API void getMonitorPhysicalSize(GLFWmonitor* monitor, int* widthMM, int* heightMM);
		//Returns the physical size of the monitor
		static ivec2 getMonitorPhysicalSize(GLFWmonitor* monitor)
		{
			ivec2 temp;
			getMonitorPhysicalSize(monitor, &temp.x, &temp.y);
			return temp;
		}

		//Retrieves the content scale for the specified monitor
		GLW_API void getMonitorContentScale(GLFWmonitor* monitor, float* xscale, float* yscale);
		//Retrieves the content scale for the specified monitor
		static vec2 getMonitorContentScale(GLFWmonitor* monitor)
		{
			vec2 temp;
			getMonitorContentScale(monitor, &temp.x, &temp.y);
			return temp;
		}

		//Returns the name of the specified monitor
		GLW_API std::string getMonitorName(GLFWmonitor* monitor);

		//Sets the user pointer of the specified monitor
		GLW_API void setMonitorUserPointer(GLFWmonitor* monitor, void* pointer);

		//Returns the user pointer of the specified monitor
		GLW_API void* getMonitorUserPointer(GLFWmonitor* monitor);

		//Sets the monitor configuration callback
		GLW_API monitorCallback setMonitorCallback(monitorCallback callback);

		//Returns the available video modes for the specified monitor
		GLW_API const GLFWvidmode* getVideoModes(GLFWmonitor* monitor, int* count);

		//Returns the current mode of the specified monitor
		GLW_API const GLFWvidmode* getVideoMode(GLFWmonitor* monitor);

		//Generates a gamma ramp and sets it for the specified monitor
		GLW_API void setGamma(GLFWmonitor* monitor, float gamma);

		//Returns the current gamma ramp for the specified monitor
		GLW_API const GLFWgammaramp* getGammaRamp(GLFWmonitor* monitor);

		//Sets the current gamma ramp for the specified monitor
		GLW_API void setGammaRamp(GLFWmonitor* monitor, const GLFWgammaramp* ramp);
	}
}