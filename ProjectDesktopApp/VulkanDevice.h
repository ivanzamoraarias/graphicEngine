#pragma once
#include "stdafx.h"
#include "VulkanInstance.h"
#include "VulkanPhisicalDevice.h"

class VulkanDevice
{
public:
	VulkanDevice(VulkanInstance* instance, VulkanPhysicalDevice* physicalDevice);
	~VulkanDevice();
	VulkanInstance* getInstance();
	VkDevice* getDevice();
	VkQueue* getComputeQueue();
	VkCommandPool& getComputeCommandPool();
	VulkanPhysicalDevice* getPhysicalDevice();
	void getComputeCommand(VkCommandBuffer* buffers, uint32_t count);
	void FreeComputeCommand(VkCommandBuffer* buffers, uint32_t count);

private:
	VulkanInstance* m_instance;
	VulkanPhysicalDevice* m_physicalDevice;
	VkDevice m_device;
	VkQueue m_computeQueue;
	VkCommandPool m_computeCommandPool;
};
