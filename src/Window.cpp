#include "Window.h"
#include "glfw/glfw3.h"

inline void GLW::defaultWindowHints()
{
	glfwDefaultWindowHints();
}

inline void GLW::windowHinti(WindowHint hint, int value)
{
	glfwWindowHint(static_cast<int>(hint), value);
}

inline void GLW::windowHint(WindowHint hint, WindowHintValue value)
{
	glfwWindowHint(static_cast<int>(hint), static_cast<int>(value));
}

inline void GLW::windowHintString(WindowStringHint hint, std::string_view value)
{
	glfwWindowHintString(static_cast<int>(hint), value.data());
}

inline GLFWwindow* GLW::createWindow(int width, int height, std::string_view title, GLFWmonitor* monitor, GLFWwindow* share)
{
	return glfwCreateWindow(width, height, title.data(), monitor, share);
}

inline void GLW::destroyWindow(GLFWwindow* window)
{
	glfwDestroyWindow(window);
}

inline bool GLW::windowShouldClose(GLFWwindow* window)
{
	return static_cast<bool>(glfwWindowShouldClose(window));
}

inline void GLW::setWindowShouldClose(GLFWwindow* window, bool value)
{
	glfwSetWindowShouldClose(window, value);
}

inline void GLW::setWindowTitle(GLFWwindow* window, std::string_view title)
{
	glfwSetWindowTitle(window, title.data());
}

inline void GLW::setWindowIcon(GLFWwindow* window, int count, const GLFWimage* images)
{
	glfwSetWindowIcon(window, count, images);
}

inline void GLW::setWindowIcon(GLFWwindow* window, int count, const Texture* images)
{
	glfwSetWindowIcon(window, count, reinterpret_cast<const GLFWimage*>(images));
}

inline void GLW::getWindowPos(GLFWwindow* window, int* xpos, int* ypos)
{
	glfwGetWindowPos(window, xpos, ypos);
}

inline GLW::ivec2 GLW::getWindowPos(GLFWwindow* window)
{
	ivec2 temp;
	getWindowPos(window, &temp.x, &temp.y);
	return temp;
}

inline void GLW::getWindowSize(GLFWwindow* window, int* width, int* height)
{
	glfwGetWindowSize(window, width, height);
}

inline GLW::ivec2 GLW::getWindowSize(GLFWwindow* window)
{
	GLW::ivec2 temp;
	getWindowSize(window, &temp.x, &temp.y);
	return temp;
}

inline void GLW::setWindowSizeLimits(GLFWwindow* window, int minwidth, int minheight, int maxwidth, int maxheight)
{
	glfwSetWindowSizeLimits(window, minwidth, minheight, maxwidth, maxheight);
}

inline void GLW::setWindowSizeLimits(GLFWwindow* window, const GLW::ivec2& mins, const GLW::ivec2& maxs)
{
	setWindowSizeLimits(window, mins.x, mins.y, maxs.x, maxs.y);
}

inline void GLW::setWindowSizeLimits(GLFWwindow* window, const GLW::ivec4& dimensions)
{
	setWindowSizeLimits(window, dimensions.x, dimensions.y, dimensions.z, dimensions.w);
}

inline void GLW::setWindowAspectRatio(GLFWwindow* window, int numer, int denom)
{
	glfwSetWindowAspectRatio(window, numer, denom);
}

inline void GLW::setWindowAspectRatio(GLFWwindow* window, const GLW::ivec2& numer_denom)
{
	glfwSetWindowAspectRatio(window, numer_denom.x, numer_denom.y);
}

inline void GLW::setWindowSize(GLFWwindow* window, int width, int height)
{
	glfwSetWindowSize(window, width, height);
}

inline void GLW::setWindowSize(GLFWwindow* window, const GLW::ivec2& width_height)
{
	setWindowSize(window, width_height.x, width_height.y);
}

inline void GLW::getFramebufferSize(GLFWwindow* window, int* width, int* height)
{
	glfwGetFramebufferSize(window, width, height);
}

inline GLW::ivec2 GLW::getFramebufferSize(GLFWwindow* window)
{
	GLW::ivec2 temp;
	getFramebufferSize(window, &temp.x, &temp.y);
	return temp;
}

inline void GLW::getWindowFrameSize(GLFWwindow* window, int* left, int* top, int* right, int* bottom)
{
	glfwGetWindowFrameSize(window, left, top, right, bottom);
}

inline GLW::ivec4 GLW::getWindowFrameSize(GLFWwindow* window)
{
	GLW::ivec4 temp;
	getWindowFrameSize(window, &temp.x, &temp.y, &temp.z, &temp.w);
	return temp;
}

inline void GLW::getWindowContentScale(GLFWwindow* window, float* xscale, float* yscale)
{
	glfwGetWindowContentScale(window, xscale, yscale);
}

inline GLW::vec2 GLW::getWindowContentScale(GLFWwindow* window)
{
	GLW::vec2 temp;
	getWindowContentScale(window, &temp.x, &temp.y);
	return temp;
}

inline float GLW::getWindowOpacity(GLFWwindow* window)
{
	return glfwGetWindowOpacity(window);
}

inline void GLW::setWindowOpacity(GLFWwindow* window, float opacity)
{
	glfwSetWindowOpacity(window, opacity);
}

inline void GLW::iconifyWindow(GLFWwindow* window)
{
	glfwIconifyWindow(window);
}

inline void GLW::restoreWindow(GLFWwindow* window)
{
	glfwRestoreWindow(window);
}

inline void GLW::maximizeWindow(GLFWwindow* window)
{
	glfwMaximizeWindow(window);
}

inline void GLW::showWindow(GLFWwindow* window)
{
	glfwShowWindow(window);
}

inline void GLW::hideWindow(GLFWwindow* window)
{
	glfwHideWindow(window);
}

inline void GLW::focusWindow(GLFWwindow* window)
{
	glfwFocusWindow(window);
}

inline void GLW::requestWindowAttention(GLFWwindow* window)
{
	glfwRequestWindowAttention(window);
}

inline GLFWmonitor* GLW::getWindowMonitor(GLFWwindow* window)
{
	return glfwGetWindowMonitor(window);
}

inline void GLW::setWindowMonitor(GLFWwindow* window, GLFWmonitor* monitor, int xpos, int ypos, int width, int height, int refreshRate)
{
	glfwSetWindowMonitor(window, monitor, xpos, ypos, width, height, refreshRate);
}

inline void GLW::setWindowMonitor(GLFWwindow* window, GLFWmonitor* monitor, const GLW::ivec2& pos, const GLW::ivec2& dimensions, int refreshRate)
{
	setWindowMonitor(window, monitor, pos.x, pos.y, dimensions.x, dimensions.y, refreshRate);
}

inline int GLW::getWindowAttribi(GLFWwindow* window, WindowAttrib attrib)
{
	return glfwGetWindowAttrib(window, static_cast<int>(attrib));
}

inline GLW::WindowHintValue GLW::getWindowAttrib(GLFWwindow* window, WindowAttrib attrib)
{
	return static_cast<WindowHintValue>(getWindowAttribi(window, attrib));
}

inline void GLW::setWindowAttribi(GLFWwindow* window, WindowAttrib attrib, int value)
{
	glfwSetWindowAttrib(window, static_cast<int>(attrib), value);
}

inline void GLW::setWindowAttrib(GLFWwindow* window, WindowAttrib attrib, WindowHintValue value)
{
	glfwSetWindowAttrib(window, static_cast<int>(attrib), static_cast<int>(value));
}

inline void GLW::setWindowUserPointer(GLFWwindow* window, void* pointer)
{
	glfwSetWindowUserPointer(window, pointer);
}

inline void* GLW::getWindowUserPointer(GLFWwindow* window)
{
	return glfwGetWindowUserPointer(window);
}

inline GLW::windowPosCallback GLW::setWindowPosCallback(GLFWwindow* window, windowPosCallback callback)
{
	return glfwSetWindowPosCallback(window, callback);
}

inline GLW::windowSizeCallback GLW::setWindowSizeCallback(GLFWwindow* window, windowSizeCallback callback)
{
	return glfwSetWindowSizeCallback(window, callback);
}

inline GLW::windowCloseCallback GLW::setWindowCloseCallback(GLFWwindow* window, windowCloseCallback callback)
{
	return glfwSetWindowCloseCallback(window, callback);
}

inline GLW::windowRefreshCallback GLW::setWindowRefreshCallback(GLFWwindow* window, windowRefreshCallback callback)
{
	return glfwSetWindowRefreshCallback(window, callback);
}

inline GLW::windowFocusCallback GLW::setWindowFocusCallback(GLFWwindow* window, windowFocusCallback callback)
{
	return glfwSetWindowFocusCallback(window, callback);
}

inline GLW::windowIconifyCallback GLW::setWindowIconifyCallback(GLFWwindow* window, windowIconifyCallback callback)
{
	return glfwSetWindowIconifyCallback(window, callback);
}

inline GLW::windowMaximizeCallback GLW::setWindowMaximizeCallback(GLFWwindow* window, windowMaximizeCallback callback)
{
	return glfwSetWindowMaximizeCallback(window, callback);
}

inline GLW::framebufferSizeCallback GLW::setFramebufferSizeCallback(GLFWwindow* window, framebufferSizeCallback callback)
{
	return glfwSetFramebufferSizeCallback(window, callback);
}

inline GLW::windowContentScaleCallback GLW::setWindowContentScaleCallback(GLFWwindow* window, windowContentScaleCallback callback)
{
	return glfwSetWindowContentScaleCallback(window, callback);
}

inline void GLW::pollEvents()
{
	glfwPollEvents();
}

inline void GLW::waitEvents()
{
	glfwWaitEvents();
}

inline void GLW::waitEventsTimeout(double timeout)
{
	glfwWaitEventsTimeout(timeout);
}

inline void GLW::postEmptyEvent()
{
	glfwPostEmptyEvent();
}

inline void GLW::swapBuffers(GLFWwindow* window)
{
	glfwSwapBuffers(window);
}
