#pragma once
#include "stdafx.h";
#include "VulkanConfiguration.h";

namespace Initializers {
	VkApplicationInfo getApplicationInfo(VulkanConfiguration& config);
	VkInstanceCreateInfo instanceCreateInfo(VkApplicationInfo& appInfo, std::vector<const char*>& layers, std::vector<const char*>& extensions);
	VkDeviceQueueCreateInfo deviceQueueCreate(uint32_t queueFamilyIndex, float& priority);
	VkDeviceCreateInfo deviceCreateInfo(std::vector<VkDeviceQueueCreateInfo>& queueCreateInfo, VkPhysicalDeviceFeatures& deviceFeatures);
	VkCommandPoolCreateInfo commandPoolCreateInfo(uint32_t queueFamilyIndex, VkCommandPoolCreateFlags flags = 0);
	VkCommandBufferAllocateInfo commandBufferAllocateInfo(VkCommandPool pool, uint32_t count);
}