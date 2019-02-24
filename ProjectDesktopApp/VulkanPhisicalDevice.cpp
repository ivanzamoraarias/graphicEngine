#include "stdafx.h"
#include "VulkanPhisicalDevice.h"

VulkanPhysicalDevice::~VulkanPhysicalDevice()
{
}

VkPhysicalDevice & VulkanPhysicalDevice::getPhysicalDevice()
{
	return m_device;
}



QueFamilyIndices & VulkanPhysicalDevice::getQueueFamilyIndeces()
{
	return m_queueIndeces;
}

VkPhysicalDeviceProperties & VulkanPhysicalDevice::getPhysicarDeviceProperties()
{
	return physicalDeviceProperties;
}

VkPhysicalDeviceFeatures & VulkanPhysicalDevice::getPhysicalDeviceFeatures()
{
	return physicalDeviceFeatures;
}

VkPhysicalDeviceMemoryProperties & VulkanPhysicalDevice::getPhysicalDeviceMemoryProperties()
{
	return physicalDeviceMemoryProperties;
}

VulkanPhysicalDevice::VulkanPhysicalDevice(VulkanInstance* instance, VkPhysicalDevice device, QueFamilyIndices indices)
{
	m_device = device;
	m_instance = instance;
	m_queueIndeces = indices;

	vkGetPhysicalDeviceProperties(m_device, &physicalDeviceProperties);
	vkGetPhysicalDeviceFeatures(m_device, &physicalDeviceFeatures);
	vkGetPhysicalDeviceMemoryProperties(m_device, &physicalDeviceMemoryProperties);
}

std::vector<VkPhysicalDevice> VulkanPhysicalDevice::getAvailablePhysicalDevices(VulkanInstance * instance)
{
	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices(
		instance ->getInstance(),
		&deviceCount,
		nullptr
	);
	
	std::vector<VkPhysicalDevice> devices(deviceCount);
	
	vkEnumeratePhysicalDevices(
		instance->getInstance(),
		&deviceCount,
		devices.data()
	);

	return devices;
}

bool VulkanPhysicalDevice::isDeviceSupported(VkPhysicalDevice& device, QueFamilyIndices& family)
{
	bool supported = isSupportedByFamily(device, family);

	return supported;
}

bool VulkanPhysicalDevice::isSupportedByFamily(VkPhysicalDevice & device, QueFamilyIndices & familes)
{
	uint32_t familyCount = 0;

	vkGetPhysicalDeviceQueueFamilyProperties(device, &familyCount, nullptr);
	std::vector<VkQueueFamilyProperties> queue_families(familyCount);
	vkGetPhysicalDeviceQueueFamilyProperties(device, &familyCount, queue_families.data());

	uint32_t i = 0;
	for (auto& queueFamily : queue_families) {
		if (queueFamily.queueCount > 0) {
			if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)
				familes.GraphicsIndices = i;
			if (queueFamily.queueFlags & VK_QUEUE_COMPUTE_BIT)
				familes.ComputeIndices = i;
		}
		
		if (familes.GraphicsIndices < UINT32_MAX && familes.GraphicsIndices < UINT32_MAX)
			return true;
		i++;
	}

	return false;
}

VulkanPhysicalDevice * VulkanPhysicalDevice::getPhysicalDevice(VulkanInstance * instance)
{
	std::vector<VkPhysicalDevice> devices = getAvailablePhysicalDevices(instance);

	VkPhysicalDevice secondaryDevice = VK_NULL_HANDLE;
	QueFamilyIndices secondaryQueue;

	for (auto& device : devices) {
		QueFamilyIndices family;

		if (isDeviceSupported(device, family)) {
			VkPhysicalDeviceProperties deviceProperties;
			vkGetPhysicalDeviceProperties(device, &deviceProperties);

			if (deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
				return new VulkanPhysicalDevice(instance, device, family);
			}
			else{
				secondaryDevice = device;
				secondaryQueue = family;
			}
		}
	}
	if (secondaryDevice == VK_NULL_HANDLE) return nullptr;

	return new VulkanPhysicalDevice(instance, secondaryDevice, secondaryQueue);
}
