#include "Vulkan.h"

#ifdef GLW_VULKAN
	inline bool GLW::vulkanSupported()
	{
		return glfwVulkanSupported();
	}

	inline const char** GLW::getRequiredInstanceExtensions(uint32_t* count)
	{
		return glfwGetRequiredInstanceExtensions(count);
	}

	std::vector<const char*> GLW::getRequiredInstanceExtensions()
	{
		std::vector<const char*> temp;
		uint32_t count;
	
		const char** temp2 = getRequiredInstanceExtensions(&count);
		temp.resize(count);
		memcpy_s(&temp.front(), count, temp2, count);
		return temp;
	}

	#ifdef VK_VERSION_1_0
		inline GLFWvkproc GLW::getInstanceProcAddress(VkInstance instance, std::string_view procname)
		{
			return glfwGetInstanceProcAddress(instance, procname.data());
		}

		inline int GLW::getPhysicalDevicePresentationSupport(VkInstance instance, VkPhysicalDevice device, uint32_t queuefamily)
		{
			return glfwGetPhysicalDevicePresentationSupport(instance, device, queuefamily);
		}

		inline VkResult GLW::createWindowSurface(VkInstance instance, GLFWwindow* window, const VkAllocationCallbacks* allocator, VkSurfaceKHR* surface)
		{
			return glfwCreateWindowSurface(instance, window, allocator, surface);
		}
	#endif
#endif