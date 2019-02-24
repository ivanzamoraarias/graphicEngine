#pragma once
#include "stdafx.h"
#include "VulkanInstance.h"
#include "QueFamilyIndices.h"

class VulkanInstance;

class VulkanPhysicalDevice {
public:
	~VulkanPhysicalDevice();
	VkPhysicalDevice& getPhysicalDevice();
	QueFamilyIndices& getQueueFamilyIndeces();
	VkPhysicalDeviceProperties& getPhysicarDeviceProperties();
	VkPhysicalDeviceFeatures& getPhysicalDeviceFeatures();
	VkPhysicalDeviceMemoryProperties& getPhysicalDeviceMemoryProperties();
	static VulkanPhysicalDevice* getPhysicalDevice(VulkanInstance* instance);
private:
	VulkanPhysicalDevice(VulkanInstance* instance, VkPhysicalDevice device, QueFamilyIndices indices);
	static std::vector<VkPhysicalDevice> getAvailablePhysicalDevices(VulkanInstance* instance);
	static bool isDeviceSupported(VkPhysicalDevice& device, QueFamilyIndices& family);
	static bool isSupportedByFamily(VkPhysicalDevice& device, QueFamilyIndices& family);
	VulkanInstance* m_instance;
	VkPhysicalDevice m_device;
	QueFamilyIndices m_queueIndeces;
	VkPhysicalDeviceProperties physicalDeviceProperties;
	VkPhysicalDeviceFeatures physicalDeviceFeatures;
	VkPhysicalDeviceMemoryProperties physicalDeviceMemoryProperties;
};