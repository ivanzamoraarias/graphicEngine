#include "stdafx.h"
#include "Initializers.h"

VkApplicationInfo Initializers::getApplicationInfo(VulkanConfiguration& config)
{
	VkApplicationInfo info = {};
	info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	info.pApplicationName = config.applicationName;
	info.pEngineName = config.engineName;
	info.applicationVersion = config.applicationVersion;
	info.engineVersion = config.engineVersion;
	info.apiVersion = config.apiVersion;

	return info;
}

VkInstanceCreateInfo Initializers::instanceCreateInfo(VkApplicationInfo& appInfo, std::vector<const char*>& layers, std::vector<const char*>& extensions)
{
	VkInstanceCreateInfo info = {};
	info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	info.pApplicationInfo = &appInfo;
	info.enabledExtensionCount = extensions.size();
	info.enabledLayerCount = extensions.size();
	info.ppEnabledExtensionNames = extensions.data();
	info.ppEnabledLayerNames = layers.data();
	return info;
}

VkDeviceQueueCreateInfo Initializers::deviceQueueCreate(uint32_t queueFamilyIndex, float& priority)
{
	VkDeviceQueueCreateInfo queueCreateInfo{};
	queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	queueCreateInfo.queueFamilyIndex = queueFamilyIndex;
	queueCreateInfo.queueCount = 1;
	queueCreateInfo.pQueuePriorities = &priority;
	return queueCreateInfo;
}

VkDeviceCreateInfo Initializers::deviceCreateInfo(std::vector<VkDeviceQueueCreateInfo>& queueCreateInfo, VkPhysicalDeviceFeatures& deviceFeatures)
{
	VkDeviceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	createInfo.pQueueCreateInfos = queueCreateInfo.data();
	createInfo.queueCreateInfoCount = (uint32_t)queueCreateInfo.size();
	createInfo.pEnabledFeatures = &deviceFeatures;
	return createInfo;
}

VkCommandPoolCreateInfo Initializers::commandPoolCreateInfo(uint32_t queueFamilyIndex, VkCommandPoolCreateFlags flags)
{
	VkCommandPoolCreateInfo poolInfo{};
	poolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
	poolInfo.queueFamilyIndex = queueFamilyIndex;
	poolInfo.flags = flags;

	return poolInfo;

}

VkCommandBufferAllocateInfo Initializers::commandBufferAllocateInfo(VkCommandPool pool, uint32_t count)
{
	VkCommandBufferAllocateInfo allocateInfo{};
	allocateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
	allocateInfo.commandPool = pool;
	allocateInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
	allocateInfo.commandBufferCount = count;
	return allocateInfo;
}

VkBufferCreateInfo Initializers::bufferCreateInfo(VkDeviceSize size, VkBufferUsageFlags usage)
{
	VkBufferCreateInfo info{};
	info.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
	info.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
	info.size = size;
	info.usage = usage;
	return info;
}

VkMemoryAllocateInfo Initializers::memoryAllocateInfo(VkDeviceSize size, uint32_t memoryTypeIndex)
{
	VkMemoryAllocateInfo info{};
	info.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
	info.allocationSize = size;
	info.memoryTypeIndex = memoryTypeIndex;
	return info;
}
