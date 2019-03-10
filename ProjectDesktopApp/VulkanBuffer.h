#pragma once
#include <vulkan/vulkan.h>
#include "VulkanDevice.h"
#include "VulkanPhisicalDevice.h"
#include "Initializers.h"

class VulkanDevice;
class VulkanBuffer
{
public:
	VulkanBuffer(VulkanDevice* device, void* ptr, unsigned int elementSize, unsigned int count = 1);
	~VulkanBuffer();

	virtual void setData();
	virtual void setData(unsigned int count);
	virtual void setData(unsigned int startIndex, unsigned int count);

private:
	void createBuffer();
	uint32_t findMemoryType(VkMemoryPropertyFlags properties, uint32_t typeFilter);
	VulkanDevice * m_device;
	void* m_ptr;
	void* m_mappedMemory;
	unsigned int m_elementSize;
	unsigned int m_count;
	VkDeviceSize m_totalSize;
	VkBuffer m_buffer;
	VkDeviceMemory m_deviceMemory;

};

