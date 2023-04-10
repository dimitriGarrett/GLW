#pragma once

#include "API.h"
#include "Vector.h"

#include "Window.h"

#include <string_view>
#include <iostream>

namespace GLW
{
	//https://www.glfw.org/docs/3.3/modules.html
	struct WindowWrapper
	{
		explicit WindowWrapper(unsigned int width, unsigned int height, std::string_view Name)
			: dimensions((width << 16) | height), name(Name)
		{
		}

		~WindowWrapper()
		{
			GLW::Window::destroyWindow(window);
		}

		operator GLFWwindow*() const
		{
			return window;
		}

		void create(GLFWmonitor* monitor = nullptr, GLFWwindow* share = nullptr)
		{
			window = GLW::Window::createWindow(width(), height(), name.c_str(), monitor, share);

			if (window == nullptr)
			{
				auto err = GLW::Init::getError();

				if (err.first != GLW::ErrorCode::NO_ERROR)
				{
					std::cout << err.second << std::endl;
				}
			}

			Context::makeContextCurrent(window);
		}

		inline void defaultWindowHints() const
		{
			GLW::Window::defaultWindowHints();
		}

		inline void windowHinti(WindowHint hint, int value) const
		{
			GLW::Window::windowHinti(hint, value);
		}
		
		inline void windowHint(WindowHint hint, WindowHintValue value) const
		{
			GLW::Window::windowHint(hint, value);
		}

		inline void windowHintString(WindowStringHint hint, std::string_view value) const
		{
			GLW::Window::windowHintString(hint, value);
		}

		inline bool windowShouldClose() const
		{
			return GLW::Window::windowShouldClose(window);
		}

		inline void setWindowShouldClose(bool value) const
		{
			GLW::Window::setWindowShouldClose(window, value);
		}

		inline void setWindowTitle(std::string_view title) const
		{
			GLW::Window::setWindowTitle(window, title);
		}

		inline void setWindowIcon(int count, const GLFWimage* images) const
		{
			GLW::Window::setWindowIcon(window, count, images);
		}

		inline void getWindowPos(int* xpos, int* ypos) const
		{
			GLW::Window::getWindowPos(window, xpos, ypos);
		}

		inline ivec2 getWindowPos() const
		{
			return GLW::Window::getWindowPos(window);
		}

		inline void getWindowSize(int* width, int* height) const
		{
			GLW::Window::getWindowSize(window, width, height);
		}
		
		inline ivec2 getWindowSize() const
		{
			return GLW::Window::getWindowSize(window);
		}
		
		inline void setWindowSizeLimits(int minwidth, int minheight, int maxwidth, int maxheight) const
		{
			GLW::Window::setWindowSizeLimits(window, minwidth, minheight, maxwidth, maxheight);
		}
		
		inline void setWindowSizeLimits(const ivec2& mins, const ivec2& maxs) const
		{
			GLW::Window::setWindowSizeLimits(window, mins, maxs);
		}
		
		inline void setWindowSizeLimits(const ivec4& dimensions) const
		{
			GLW::Window::setWindowSizeLimits(window, dimensions);
		}

		inline void setWindowAspectRatio(int numer, int denom) const
		{
			GLW::Window::setWindowAspectRatio(window, numer, denom);
		}
		
		inline void setWindowAspectRatio(const ivec2& numer_denom) const
		{
			GLW::Window::setWindowAspectRatio(window, numer_denom);
		}
		
		inline void setWindowSize(int width, int height)
		{
			GLW::Window::setWindowSize(window, width, height);
			dimensions = (width << 16) | height;
		}
		
		inline void setWindowSize(const ivec2& width_height)
		{
			GLW::Window::setWindowSize(window, width_height);
			dimensions = (width_height.x << 16) | width_height.y;
		}

		inline void getFramebufferSize(int* width, int* height) const
		{
			GLW::Window::getFramebufferSize(window, width, height);
		}
		
		inline ivec2 getFramebufferSize() const
		{
			return GLW::Window::getFramebufferSize(window);
		}

		inline void getWindowFrameSize(int* left, int* top, int* right, int* bottom) const
		{
			GLW::Window::getWindowFrameSize(window, left, top, right, bottom);
		}

		inline ivec4 getWindowFrameSize() const
		{
			return GLW::Window::getWindowFrameSize(window);
		}

		inline void getWindowContentScale(float* xscale, float* yscale) const
		{
			GLW::Window::getWindowContentScale(window, xscale, yscale);
		}
		
		inline vec2 getWindowContentScale() const
		{
			return GLW::Window::getWindowContentScale(window);
		}

		inline float getWindowOpacity() const
		{
			return GLW::Window::getWindowOpacity(window);
		}

		inline void setWindowOpacity(float opacity) const
		{
			GLW::Window::setWindowOpacity(window, opacity);
		}

		inline void iconifyWindow() const
		{
			GLW::Window::iconifyWindow(window);
		}

		inline void restoreWindow() const
		{
			GLW::Window::restoreWindow(window);
		}

		inline void maximizeWindow() const
		{
			GLW::Window::maximizeWindow(window);
		}

		inline void showWindow() const
		{
			GLW::Window::showWindow(window);
		}

		inline void hideWindow() const
		{
			GLW::Window::hideWindow(window);
		}

		inline void focusWindow() const
		{
			GLW::Window::focusWindow(window);
		}

		inline void requestWindowAttention() const
		{
			GLW::Window::requestWindowAttention(window);
		}

		inline GLFWmonitor* getWindowMonitor() const
		{
			return GLW::Window::getWindowMonitor(window);
		}

		inline void setWindowMonitor(GLFWmonitor* monitor, int xpos, int ypos, int width, int height, int refreshRate) const
		{
			GLW::Window::setWindowMonitor(window, monitor, xpos, ypos, width, height, refreshRate);
		}
		
		inline void setWindowMonitor(GLFWmonitor* monitor, const ivec2& pos, const ivec2& dimensions, int refreshRate) const
		{
			GLW::Window::setWindowMonitor(window, monitor, pos, dimensions, refreshRate);
		}

		inline int getWindowAttribi(WindowAttrib attrib) const
		{
			return GLW::Window::getWindowAttribi(window, attrib);
		}
		
		inline WindowHintValue getWindowAttrib(WindowAttrib attrib) const
		{
			return GLW::Window::getWindowAttrib(window, attrib);
		}

		inline void setWindowAttribi(WindowAttrib attrib, int value) const
		{
			GLW::Window::setWindowAttribi(window, attrib, value);
		}
		
		inline void setWindowAttrib(WindowAttrib attrib, WindowHintValue value) const
		{
			GLW::Window::setWindowAttrib(window, attrib, value);
		}

		inline void setWindowUserPointer(void* pointer) const
		{
			GLW::Window::setWindowUserPointer(window, pointer);
		}

		inline void* getWindowUserPointer() const
		{
			return GLW::Window::getWindowUserPointer(window);
		}

		inline windowPosCallback setWindowPosCallback(windowPosCallback callback) const
		{
			return GLW::Window::setWindowPosCallback(window, callback);
		}

		inline windowSizeCallback setWindowSizeCallback(windowSizeCallback callback)
		{
			return GLW::Window::setWindowSizeCallback(window, callback);
		}

		inline windowCloseCallback setWindowCloseCallback(windowCloseCallback callback) const
		{
			return GLW::Window::setWindowCloseCallback(window, callback);
		}

		inline windowRefreshCallback setWindowRefreshCallback(windowRefreshCallback callback) const
		{
			return GLW::Window::setWindowRefreshCallback(window, callback);
		}

		inline windowFocusCallback setWindowFocusCallback(windowFocusCallback callback) const
		{
			return GLW::Window::setWindowFocusCallback(window, callback);
		}

		inline windowIconifyCallback setWindowIconifyCallback(windowIconifyCallback callback) const
		{
			return GLW::Window::setWindowIconifyCallback(window, callback);
		}

		inline windowMaximizeCallback setWindowMaximizeCallback(windowMaximizeCallback callback) const
		{
			return GLW::Window::setWindowMaximizeCallback(window, callback);
		}

		inline framebufferSizeCallback setFramebufferSizeCallback(framebufferSizeCallback callback) const
		{
			return GLW::Window::setFramebufferSizeCallback(window, callback);
		}

		inline windowContentScaleCallback setWindowContentScaleCallback(windowContentScaleCallback callback) const
		{
			return GLW::Window::setWindowContentScaleCallback(window, callback);
		}

		inline static void pollEvents()
		{
			GLW::Window::pollEvents();
		}

		inline static void waitEvents()
		{
			GLW::Window::waitEvents();
		}

		inline static void waitEventsTimeout(double timeout)
		{
			GLW::Window::waitEventsTimeout(timeout);
		}

		inline static void postEmptyEvent()
		{
			GLW::Window::postEmptyEvent();
		}

		inline void swapBuffers() const
		{
			GLW::Window::swapBuffers(window);
		}

		inline bool open() const
		{
			return !GLW::Window::windowShouldClose(window);
		}

		inline void update() const
		{
			swapBuffers();
			pollEvents();
		}

		inline unsigned int width() const
		{
			return dimensions >> 16;
		}

		inline unsigned int height() const
		{
			return dimensions & 0x0000FFFF;
		}

		uint32_t dimensions = 0;
		std::string name = "";

		GLFWwindow* window;
	};
}