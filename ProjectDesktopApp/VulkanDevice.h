#pragma once
#include "stdafx.h"
#include "BUILD_ORDER.h";

class VulkanPhysicalDevice;

class VulkanDevice
{
public:
	VulkanDevice(VulkanInstance* instance, VulkanPhysicalDevice* physicalDevice);
	~VulkanDevice();
	VulkanInstance* getInstance();
	VkDevice* getDevice();
	VkQueue* getComputeQueue();


private:
	VulkanInstance* m_instance;
	VulkanPhysicalDevice* m_physicalDevice;
	VkDevice m_device;
	VkQueue m_computeQueue;
};
