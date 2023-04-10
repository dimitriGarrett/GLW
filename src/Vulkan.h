#pragma once

#ifdef GLW_VULKAN
// remove this if you want to include your own vulkan headers
	#define GLFW_INCLUDE_VULKAN
	#include "glfw/glfw3.h"

	#include "API.h"

	#include <vector>
	#include <string_view>

	namespace GLW
	{
		namespace Vulkan
		{
			//Returns whether the Vulkan loader and an ICD have been found
			GLW_API bool vulkanSupported();

			//Returns the Vulkan instance extensions required by GLFW
			GLW_API const char** getRequiredInstanceExtensions(uint32_t* count);
			//Returns the Vulkan instance extensions required by GLFW
			GLW_API std::vector<const char*> getRequiredInstanceExtensions();

	#ifdef VK_VERSION_1_0
			//Returns the address of the specified Vulkan instance function
			GLW_API GLFWvkproc getInstanceProcAddress(VkInstance instance, std::string_view procname);

			//Returns whether the specified queue family can present images
			GLW_API int getPhysicalDevicePresentationSupport(VkInstance instance, VkPhysicalDevice device, uint32_t queuefamily);

			//Creates a Vulkan surface for the specified window
			GLW_API VkResult createWindowSurface(VkInstance instance, GLFWwindow* window, const VkAllocationCallbacks* allocator, VkSurfaceKHR* surface);
	#endif
		}
	}
#endif