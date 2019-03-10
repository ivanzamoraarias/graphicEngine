#include "stdafx.h"
#include "VulkanBuffer.h"
#include "VulkanDevice.h"
#include "VulkanPhisicalDevice.h"
#include "Initializers.h"
#include "Validation.h"


VulkanBuffer::VulkanBuffer(VulkanDevice * device, void* ptr, unsigned int elementSize, unsigned int count)
{
	m_device = device;
	m_ptr = ptr;
	m_count = count;
	m_elementSize = elementSize;
	m_totalSize = m_elementSize * m_count;


	createBuffer();
}

VulkanBuffer::~VulkanBuffer()
{
	vkUnmapMemory(
		*m_device->getDevice(),
		m_deviceMemory
	);

	vkDestroyBuffer(
		*m_device->getDevice(),
		m_buffer, 
		nullptr
	);

	vkFreeMemory(
		*m_device->getDevice(),
		m_deviceMemory,
		nullptr 
	);
}

void VulkanBuffer::setData()
{
	memcpy(m_mappedMemory, m_ptr, (unsigned int)m_totalSize);
}

void VulkanBuffer::setData(unsigned int count)
{
	memcpy(m_mappedMemory, m_ptr, m_elementSize*count);
}

void VulkanBuffer::setData(unsigned int startIndex, unsigned int count)
{
	memcpy(
		((char*)m_mappedMemory)+(startIndex*m_elementSize), 
		((char*)m_ptr) + (startIndex*m_elementSize),
		m_elementSize*count);
}

void VulkanBuffer::createBuffer()
{
	VkBufferCreateInfo bufferInfo =
		Initializers::bufferCreateInfo(m_totalSize, VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT);
	checkError(
		vkCreateBuffer(*m_device->getDevice, &bufferInfo, nullptr, &m_buffer)
	);
	VkMemoryRequirements memoryRequirements;


	vkGetBufferMemoryRequirements(
		*m_device->getDevice
		, m_buffer
		, &memoryRequirements
	);

	VkMemoryAllocateInfo allocateInfo =
		Initializers::memoryAllocateInfo(
			memoryRequirements.size,
			findMemoryType(VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT, memoryRequirements.memoryTypeBits));
	checkError(
		vkAllocateMemory(
			*m_device->getDevice(),
			&allocateInfo,
			nullptr,
			&m_deviceMemory
		)
	);

	checkError(
		vkBindBufferMemory(
			*m_device->getDevice(),
			m_buffer,
			m_deviceMemory,
			0
		)
	);
	vkMapMemory(
		*m_device->getDevice(),
		m_deviceMemory,
		0, memoryRequirements.size,0, &m_mappedMemory
	);
}

uint32_t VulkanBuffer::findMemoryType(VkMemoryPropertyFlags properties, uint32_t typeFilter)
{
	for (uint32_t i = 0; i < m_device->getPhysicalDevice().getPhysicalDeviceMemoryProperties().memoryTypeCount; i++) {
		if ((typeFilter & (1 << i)) && m_device->getPhysicalDevice().getPhysicalDeviceMemoryProperties().memoryTypes[i].propertyFlags & properties == properties) {
			return i;
		}
	}
	assert(0 && "There are not available memory properties");
	return -1;
}
