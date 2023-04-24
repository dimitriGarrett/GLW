#pragma once

#include "API.h"
#include "Vector.h"

#include <string_view>

struct GLFWwindow;
struct GLFWmonitor;
struct GLFWimage;

#ifdef _WIN32
	#undef NO_ERROR
#endif

namespace GLW
{
	enum class WindowHint : unsigned int
	{
		STEREO = 0x0002100C,
		DOUBLEBUFFER = 0x00021010,

		RESIZABLE = 0x00020003,
		VISIBLE = 0x00020004,
		DECORATED = 0x00020005,
		FOCUSED = 0x00020001,
		AUTO_ICONIFY = 0x00020006,
		FLOATING = 0x00020007,
		MAXIMIZED = 0x00020008,
		CENTER_CURSOR = 0x00020009,
		TRANSPARENT_FRAMEBUFFER = 0x0002000A,
		FOCUS_ON_SHOW = 0x0002000C,
		SCALE_TO_MONITOR = 0x0002200C,

		RED_BITS = 0x00021001,
		GREEN_BITS = 0x00021002,
		BLUE_BITS = 0x00021003,
		ALPHA_BITS = 0x00021004,
		DEPTH_BITS = 0x00021005,
		STENCIL_BITS = 0x00021006,

		ACCUM_RED_BITS = 0x00021007,
		ACCUM_GREEN_BITS = 0x00021008,
		ACCUM_BLUE_BITS = 0x00021009,
		ACCUM_ALPHA_BITS = 0x0002100A,

		AUX_BUFFERS = 0x0002100B,
		SAMPLES = 0x0002100D,
		SRGB_CAPABLE = 0x0002100E,

		REFRESH_RATE = 0x0002100F,

		CLIENT_API = 0x00022001,
		CONTEXT_CREATION_API = 0x0002200B,
		CONTEXT_VERSION_MAJOR = 0x00022002,
		CONTEXT_VERSION_MINOR = 0x00022003,
		OPENGL_FORWARD_COMPAT = 0x00022006,
		OPENGL_DEBUG_CONTEXT = 0x00022007,
		OPENGL_PROFILE = 0x00022008,
		CONTEXT_ROBUSTNESS = 0x00022005,
		CONTEXT_RELEASE_BEHAVIOR = 0x00022009,
		CONTEXT_NO_ERROR = 0x0002200A,

#ifdef __APPLE__
		COCOA_RETINA_FRAMEBUFFER = 0x00023001,
		COCOA_GRAPHICS_SWITCHING = 0x00023003
#endif
	};

	enum class WindowStringHint : unsigned int
	{
#ifdef __APPLE__
		COCOA_FRAME_NAME = 0x00023002,
		X11_CLASS_NAME = 0x00024001,
		X11_INSTANCE_NAME = 0x00024002,
#endif
	};

	enum class WindowHintValue : unsigned int
	{
		FALSE = 0,
		TRUE = 1,

		DONT_CARE = -1,

		NO_API = 0,
		OPENGL_API = 0x00030001,
		OPENGL_ES_API = 0x00030002,

		NATIVE_CONTEXT_API = 0x00036001,
		EGL_CONTEXT_API = 0x00036002,
		OSMESA_CONTEXT_API = 0x00036003,

		NO_ROBUSTNESS = 0,
		NO_RESET_NOTIFICATION = 0x00031001,
		LOSE_CONTEXT_ON_RESET = 0x00031002,

		ANY_RELEASE_BEHAVIOR = 0,
		RELEASE_BEHAVIOR_FLUSH = 0x00035001,
		RELEASE_BEHAVIOR_NONE  = 0x00035002,

		OPENGL_ANY_PROFILE = 0,
		OPENGL_CORE_PROFILE = 0x00032001,
		OPENGL_COMPAT_PROFILE = 0x00032002
	};

	enum class WindowAttrib : unsigned int
	{
		FOCUSED = 0x00020001,
		ICONIFIED = 0x00020002,
		MAXIMIZED = 0x00020008,
		HOVERED = 0x0002000B,
		VISIBLE = 0x00020004,
		RESIZABLE = 0x00020003,
		DECORATED = 0x00020005,
		AUTO_ICONIFY = 0x00020006,
		FLOATING = 0x00020007,
		TRANSPARENT_FRAMEBUFFER = 0x0002000A,
		FOCUS_ON_SHOW = 0x0002000C,

		CLIENT_API = 0x00022001,
		CONTEXT_CREATION_API = 0x0002200B,
		CONTEXT_VERSION_MAJOR = 0x00022002,
		CONTEXT_VERSION_MINOR = 0x00022003,
		CONTEXT_REVISION = 0x00022004,

		OPENGL_FORWARD_COMPAT = 0x00022006,
		OPENGL_DEBUG_CONTEXT = 0x00022007,
		OPENGL_PROFILE = 0x00022008,
		CONTEXT_RELEASE_BEHAVIOR = 0x00022009,
		CONTEXT_NO_ERROR = 0x0002200A,
		CONTEXT_ROBUSTNESS = 0x00022005,

		RED_BITS = 0x00021001,
		GREEN_BITS = 0x00021002,
		BLUE_BITS = 0x00021003,
		ALPHA_BITS = 0x00021004,
		DEPTH_BITS = 0x00021005,
		STENCIL_BITS = 0x00021006,
		SAMPLES = 0x0002100D
	};

	using windowPosCallback = void(*)(GLFWwindow*, int, int);
	using windowSizeCallback = void(*)(GLFWwindow*, int, int);
	using windowCloseCallback = void(*)(GLFWwindow*);
	using windowCloseCallback = void(*)(GLFWwindow*);
	using windowRefreshCallback = void(*)(GLFWwindow*);
	using windowFocusCallback = void(*)(GLFWwindow*, int);
	using windowIconifyCallback = void(*)(GLFWwindow*, int);
	using windowMaximizeCallback = void(*)(GLFWwindow*, int);
	using framebufferSizeCallback = void(*)(GLFWwindow*, int, int);
	using windowContentScaleCallback = void(*)(GLFWwindow*, float, float);

	//Resets all window hints to their default values
	GLW_API void defaultWindowHints();

	//Sets the specified window hint to the desired value
	GLW_API void windowHinti(WindowHint hint, int value);
	//Sets the specified window hint to the desired value
	GLW_API void windowHint(WindowHint hint, WindowHintValue value);

	//Sets the specified window hint to the desired value
	GLW_API void windowHintString(WindowStringHint hint, std::string_view value);

	//Creates a window and its associated context
	GLW_API GLFWwindow* createWindow(int width, int height, std::string_view title, GLFWmonitor* monitor, GLFWwindow* share);

	//Destroys the specified window and its context
	GLW_API void destroyWindow(GLFWwindow* window);

	//Checks the close flag of the specified window
	GLW_API bool windowShouldClose(GLFWwindow* window);

	//Sets the close flag of the specified window
	GLW_API void setWindowShouldClose(GLFWwindow* window, bool value);

	//Sets the title of the specified window
	GLW_API void setWindowTitle(GLFWwindow* window, std::string_view title);

	//Sets the icon for the specified window
	GLW_API void setWindowIcon(GLFWwindow* window, int count, const GLFWimage* images);

	//Retrieves the position of the content area of the specified window
	GLW_API void getWindowPos(GLFWwindow* window, int* xpos, int* ypos);
	//Retrieves the position of the content area of the specified window
	GLW_API ivec2 getWindowPos(GLFWwindow* window);

	//Retrieves the size of the content area of the specified window
	GLW_API void getWindowSize(GLFWwindow* window, int* width, int* height);
	//Retrieves the size of the content area of the specified window
	GLW_API ivec2 getWindowSize(GLFWwindow* window);

	//Sets the size limits of the specified window
	GLW_API void setWindowSizeLimits(GLFWwindow* window, int minwidth, int minheight, int maxwidth, int maxheight);
	//Sets the size limits of the specified window
	GLW_API void setWindowSizeLimits(GLFWwindow* window, const ivec2& mins, const ivec2& maxs);
	//Sets the size limits of the specified window
	GLW_API void setWindowSizeLimits(GLFWwindow* window, const ivec4& dimensions);

	//Sets the aspect ratio of the specified window
	GLW_API void setWindowAspectRatio(GLFWwindow* window, int numer, int denom);
	//Sets the aspect ratio of the specified window
	GLW_API void setWindowAspectRatio(GLFWwindow* window, const ivec2& numer_denom);

	//Sets the size of the content area of the specified window
	GLW_API void setWindowSize(GLFWwindow* window, int width, int height);
	//Sets the size of the content area of the specified window
	GLW_API void setWindowSize(GLFWwindow* window, const ivec2& width_height);

	//Retrieves the size of the framebuffer of the specified window
	GLW_API void getFramebufferSize(GLFWwindow* window, int* width, int* height);
	//Retrieves the size of the framebuffer of the specified window
	GLW_API ivec2 getFramebufferSize(GLFWwindow* window);

	//Retrieves the size of the frame of the window
	GLW_API void getWindowFrameSize(GLFWwindow* window, int* left, int* top, int* right, int* bottom);
	//Retrieves the size of the frame of the window
	GLW_API ivec4 getWindowFrameSize(GLFWwindow* window);

	//Retrieves the content scale for the specified window
	GLW_API void getWindowContentScale(GLFWwindow* window, float* xscale, float* yscale);
	//Retrieves the content scale for the specified window
	GLW_API vec2 getWindowContentScale(GLFWwindow* window);

	//Returns the opacity of the whole window
	GLW_API float getWindowOpacity(GLFWwindow* window);

	//Sets the opacity of the whole window
	GLW_API void setWindowOpacity(GLFWwindow* window, float opacity);

	//Iconifies the specified window
	GLW_API void iconifyWindow(GLFWwindow* window);

	//Restores the specified window
	GLW_API void restoreWindow(GLFWwindow* window);

	//Maximizes the specified window
	GLW_API void maximizeWindow(GLFWwindow* window);

	//Makes the specified window visible
	GLW_API void showWindow(GLFWwindow* window);

	//Hides the specified window
	GLW_API void hideWindow(GLFWwindow* window);

	//Brings the specified window to front and sets input focus
	GLW_API void focusWindow(GLFWwindow* window);

	//Requests user attention to the specified window
	GLW_API void requestWindowAttention(GLFWwindow* window);

	//Returns the monitor that the window uses for full screen mode
	GLW_API GLFWmonitor* getWindowMonitor(GLFWwindow* window);

	//Sets the mode, monitor, video mode and placement of a window
	GLW_API void setWindowMonitor(GLFWwindow* window, GLFWmonitor* monitor, int xpos, int ypos, int width, int height, int refreshRate);
	//Sets the mode, monitor, video mode and placement of a window
	GLW_API void setWindowMonitor(GLFWwindow* window, GLFWmonitor* monitor, const ivec2& pos, const ivec2& dimensions, int refreshRate);

	//Returns an attribute of the specified window
	GLW_API int getWindowAttribi(GLFWwindow* window, WindowAttrib attrib);
	//Returns an attribute of the specified window
	GLW_API WindowHintValue getWindowAttrib(GLFWwindow* window, WindowAttrib attrib);

	//Sets an attribute of the specified window
	GLW_API void setWindowAttribi(GLFWwindow* window, WindowAttrib attrib, int value);
	//Sets an attribute of the specified window
	GLW_API void setWindowAttrib(GLFWwindow* window, WindowAttrib attrib, WindowHintValue value);

	//Sets the user pointer of the specified window
	GLW_API void setWindowUserPointer(GLFWwindow* window, void* pointer);

	//Returns the user pointer of the specified window
	GLW_API void* getWindowUserPointer(GLFWwindow* window);

	//Sets the position callback for the specified window
	GLW_API windowPosCallback setWindowPosCallback(GLFWwindow* window, windowPosCallback callback);

	//Sets the size callback for the specified window
	GLW_API windowSizeCallback setWindowSizeCallback(GLFWwindow* window, windowSizeCallback callback);

	//Sets the close callback for the specified window
	GLW_API windowCloseCallback setWindowCloseCallback(GLFWwindow* window, windowCloseCallback callback);

	//Sets the refresh callback for the specified window
	GLW_API windowRefreshCallback setWindowRefreshCallback(GLFWwindow* window, windowRefreshCallback callback);

	//Sets the focus callback for the specified window
	GLW_API windowFocusCallback setWindowFocusCallback(GLFWwindow* window, windowFocusCallback callback);

	//Sets the iconify callback for the specified window
	GLW_API windowIconifyCallback setWindowIconifyCallback(GLFWwindow* window, windowIconifyCallback callback);

	//Sets the maximize callback for the specified window
	GLW_API windowMaximizeCallback setWindowMaximizeCallback(GLFWwindow* window, windowMaximizeCallback callback);

	//Sets the framebuffer resize callback for the specified window
	GLW_API framebufferSizeCallback setFramebufferSizeCallback(GLFWwindow* window, framebufferSizeCallback callback);

	//Sets the window content scale callback for the specified window
	GLW_API windowContentScaleCallback setWindowContentScaleCallback(GLFWwindow* window, windowContentScaleCallback callback);

	//Processes all pending events
	GLW_API void pollEvents();

	//Waits until events are queued and processes them
	GLW_API void waitEvents();

	//Waits with timeout until events are queued and processes them
	GLW_API void waitEventsTimeout(double timeout);

	//Posts an empty event to the event queue
	GLW_API void postEmptyEvent();

	//Swaps the front and back buffers of the specified window
	GLW_API void swapBuffers(GLFWwindow* window);
}