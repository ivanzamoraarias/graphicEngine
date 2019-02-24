#include "stdafx.h"
#include "VulkanDevice.h"

VulkanDevice::VulkanDevice(VulkanInstance * instance, VulkanPhysicalDevice* physicalDevice)
{
	m_instance = instance;
	m_physicalDevice = physicalDevice;
	std::vector<VkDeviceQueueCreateInfo> queuesCreateInfo;
	float priority = 1.0f;
	queuesCreateInfo.push_back(
		Initializers::deviceQueueCreate(
			m_physicalDevice->getQueueFamilyIndeces().ComputeIndices,
			priority));
	VkDeviceCreateInfo createInfo = Initializers::deviceCreateInfo(
		queuesCreateInfo, 
		m_physicalDevice->getPhysicalDeviceFeatures()
	);
	checkError(
		vkCreateDevice(
			m_physicalDevice->getPhysicalDevice(),
			&createInfo,
			nullptr,
			&m_device
		)
	);

	vkGetDeviceQueue(
		m_device, 
		m_physicalDevice ->getQueueFamilyIndeces().ComputeIndices, 
		0, 
		&m_computeQueue);
}

VulkanDevice::~VulkanDevice()
{
	vkDestroyDevice(m_device, nullptr);
}

VulkanInstance * VulkanDevice::getInstance()
{
	return m_instance;
}

VkDevice * VulkanDevice::getDevice()
{
	return &m_device;
}

VkQueue * VulkanDevice::getComputeQueue()
{
	return &m_computeQueue;
}
