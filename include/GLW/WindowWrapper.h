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

		WindowWrapper(const WindowWrapper&) = delete;
		WindowWrapper& operator=(const WindowWrapper&) = delete;

		WindowWrapper(WindowWrapper&& rhs) noexcept
			: dimensions(std::exchange(rhs.dimensions, 0)), name(std::exchange(rhs.name, "")), window(std::exchange(rhs.window, nullptr))
		{
		}

		WindowWrapper& operator=(WindowWrapper&& rhs) noexcept
		{
			dimensions = std::exchange(rhs.dimensions, 0);
			name = std::exchange(rhs.name, "");
			window = std::exchange(rhs.window, nullptr);
		}

		~WindowWrapper()
		{
			GLW::destroyWindow(window);
		}

		operator GLFWwindow*() const
		{
			return window;
		}

		void create(GLFWmonitor* monitor = nullptr, GLFWwindow* share = nullptr)
		{
			window = GLW::createWindow(width(), height(), name.c_str(), monitor, share);

			if (window == nullptr)
			{
				auto err = GLW::getError();

				if (err.first != GLW::ErrorCode::NO_ERROR)
				{
					std::cout << err.second << std::endl;
				}
			}

			makeContextCurrent(window);
		}

		inline void defaultWindowHints() const
		{
			GLW::defaultWindowHints();
		}

		inline void windowHinti(WindowHint hint, int value) const
		{
			GLW::windowHinti(hint, value);
		}
		
		inline void windowHint(WindowHint hint, WindowHintValue value) const
		{
			GLW::windowHint(hint, value);
		}

		inline void windowHintString(WindowStringHint hint, std::string_view value) const
		{
			GLW::windowHintString(hint, value);
		}

		inline bool windowShouldClose() const
		{
			return GLW::windowShouldClose(window);
		}

		inline void setWindowShouldClose(bool value) const
		{
			GLW::setWindowShouldClose(window, value);
		}

		inline void setWindowTitle(std::string_view title) const
		{
			GLW::setWindowTitle(window, title);
		}

		inline void setWindowIcon(int count, const GLFWimage* images) const
		{
			GLW::setWindowIcon(window, count, images);
		}

		inline void setWindowIcon(int count, const Texture* images) const
		{
			GLW::setWindowIcon(window, count, images);
		}
		
		inline void setWindowIcon(const std::vector<Texture>& images) const
		{
			GLW::setWindowIcon(window, static_cast<int>(images.size()), images.data());
		}

		inline void getWindowPos(int* xpos, int* ypos) const
		{
			GLW::getWindowPos(window, xpos, ypos);
		}

		inline ivec2 getWindowPos() const
		{
			return GLW::getWindowPos(window);
		}

		inline void getWindowSize(int* width, int* height) const
		{
			GLW::getWindowSize(window, width, height);
		}
		
		inline ivec2 getWindowSize() const
		{
			return GLW::getWindowSize(window);
		}
		
		inline void setWindowSizeLimits(int minwidth, int minheight, int maxwidth, int maxheight) const
		{
			GLW::setWindowSizeLimits(window, minwidth, minheight, maxwidth, maxheight);
		}
		
		inline void setWindowSizeLimits(const ivec2& mins, const ivec2& maxs) const
		{
			GLW::setWindowSizeLimits(window, mins, maxs);
		}
		
		inline void setWindowSizeLimits(const ivec4& dimensions) const
		{
			GLW::setWindowSizeLimits(window, dimensions);
		}

		inline void setWindowAspectRatio(int numer, int denom) const
		{
			GLW::setWindowAspectRatio(window, numer, denom);
		}
		
		inline void setWindowAspectRatio(const ivec2& numer_denom) const
		{
			GLW::setWindowAspectRatio(window, numer_denom);
		}
		
		inline void setWindowSize(int width, int height)
		{
			GLW::setWindowSize(window, width, height);
			dimensions = (width << 16) | height;
		}
		
		inline void setWindowSize(const ivec2& width_height)
		{
			GLW::setWindowSize(window, width_height);
			dimensions = (width_height.x << 16) | width_height.y;
		}

		inline void getFramebufferSize(int* width, int* height) const
		{
			GLW::getFramebufferSize(window, width, height);
		}
		
		inline ivec2 getFramebufferSize() const
		{
			return GLW::getFramebufferSize(window);
		}

		inline void getWindowFrameSize(int* left, int* top, int* right, int* bottom) const
		{
			GLW::getWindowFrameSize(window, left, top, right, bottom);
		}

		inline ivec4 getWindowFrameSize() const
		{
			return GLW::getWindowFrameSize(window);
		}

		inline void getWindowContentScale(float* xscale, float* yscale) const
		{
			GLW::getWindowContentScale(window, xscale, yscale);
		}
		
		inline vec2 getWindowContentScale() const
		{
			return GLW::getWindowContentScale(window);
		}

		inline float getWindowOpacity() const
		{
			return GLW::getWindowOpacity(window);
		}

		inline void setWindowOpacity(float opacity) const
		{
			GLW::setWindowOpacity(window, opacity);
		}

		inline void iconifyWindow() const
		{
			GLW::iconifyWindow(window);
		}

		inline void restoreWindow() const
		{
			GLW::restoreWindow(window);
		}

		inline void maximizeWindow() const
		{
			GLW::maximizeWindow(window);
		}

		inline void showWindow() const
		{
			GLW::showWindow(window);
		}

		inline void hideWindow() const
		{
			GLW::hideWindow(window);
		}

		inline void focusWindow() const
		{
			GLW::focusWindow(window);
		}

		inline void requestWindowAttention() const
		{
			GLW::requestWindowAttention(window);
		}

		inline GLFWmonitor* getWindowMonitor() const
		{
			return GLW::getWindowMonitor(window);
		}

		inline void setWindowMonitor(GLFWmonitor* monitor, int xpos, int ypos, int width, int height, int refreshRate) const
		{
			GLW::setWindowMonitor(window, monitor, xpos, ypos, width, height, refreshRate);
		}
		
		inline void setWindowMonitor(GLFWmonitor* monitor, const ivec2& pos, const ivec2& dimensions, int refreshRate) const
		{
			GLW::setWindowMonitor(window, monitor, pos, dimensions, refreshRate);
		}

		inline int getWindowAttribi(WindowAttrib attrib) const
		{
			return GLW::getWindowAttribi(window, attrib);
		}
		
		inline WindowHintValue getWindowAttrib(WindowAttrib attrib) const
		{
			return GLW::getWindowAttrib(window, attrib);
		}

		inline void setWindowAttribi(WindowAttrib attrib, int value) const
		{
			GLW::setWindowAttribi(window, attrib, value);
		}
		
		inline void setWindowAttrib(WindowAttrib attrib, WindowHintValue value) const
		{
			GLW::setWindowAttrib(window, attrib, value);
		}

		inline void setWindowUserPointer(void* pointer) const
		{
			GLW::setWindowUserPointer(window, pointer);
		}

		inline void* getWindowUserPointer() const
		{
			return GLW::getWindowUserPointer(window);
		}

		inline windowPosCallback setWindowPosCallback(windowPosCallback callback) const
		{
			return GLW::setWindowPosCallback(window, callback);
		}

		inline windowSizeCallback setWindowSizeCallback(windowSizeCallback callback)
		{
			return GLW::setWindowSizeCallback(window, callback);
		}

		inline windowCloseCallback setWindowCloseCallback(windowCloseCallback callback) const
		{
			return GLW::setWindowCloseCallback(window, callback);
		}

		inline windowRefreshCallback setWindowRefreshCallback(windowRefreshCallback callback) const
		{
			return GLW::setWindowRefreshCallback(window, callback);
		}

		inline windowFocusCallback setWindowFocusCallback(windowFocusCallback callback) const
		{
			return GLW::setWindowFocusCallback(window, callback);
		}

		inline windowIconifyCallback setWindowIconifyCallback(windowIconifyCallback callback) const
		{
			return GLW::setWindowIconifyCallback(window, callback);
		}

		inline windowMaximizeCallback setWindowMaximizeCallback(windowMaximizeCallback callback) const
		{
			return GLW::setWindowMaximizeCallback(window, callback);
		}

		inline framebufferSizeCallback setFramebufferSizeCallback(framebufferSizeCallback callback) const
		{
			return GLW::setFramebufferSizeCallback(window, callback);
		}

		inline windowContentScaleCallback setWindowContentScaleCallback(windowContentScaleCallback callback) const
		{
			return GLW::setWindowContentScaleCallback(window, callback);
		}

		inline static void pollEvents()
		{
			GLW::pollEvents();
		}

		inline static void waitEvents()
		{
			GLW::waitEvents();
		}

		inline static void waitEventsTimeout(double timeout)
		{
			GLW::waitEventsTimeout(timeout);
		}

		inline static void postEmptyEvent()
		{
			GLW::postEmptyEvent();
		}

		inline void swapBuffers() const
		{
			GLW::swapBuffers(window);
		}

		inline bool open() const
		{
			return !GLW::windowShouldClose(window);
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

		GLFWwindow* window = nullptr;
	};
}