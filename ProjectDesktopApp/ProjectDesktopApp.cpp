// ProjectDesktopApp.cpp : Defines the entry point for the console application.
//
#include "stdafx.h";
#include "VulkanInstance.h"
#include "VulkanPhisicalDevice.h"
#include "VulkanDevice.h"
#include "VulkanBuffer.h"
 
VulkanInstance* instance;
VulkanPhysicalDevice* physicalDevice;
VulkanDevice* device; 
VulkanBuffer* buffer;

int main()
{
	VulkanConfiguration engineConfiguration;
	engineConfiguration.applicationName = "Vulkan App";
	engineConfiguration.applicationVersion = VK_MAKE_VERSION(1,0,0);

	instance = new VulkanInstance(engineConfiguration);
	physicalDevice = VulkanPhysicalDevice::getPhysicalDevice(instance);
	device = new VulkanDevice(instance,physicalDevice);

	VkCommandBuffer *commands = new VkCommandBuffer[3];
	device->getComputeCommand(commands, 3);

	float* memoryArray = new float[3];
	for (int i = 0; i < 3; i++)
		memoryArray[i] = i;

	buffer = new VulkanBuffer(device, memoryArray, sizeof(float),3);

	buffer->setData();

	device->FreeComputeCommand(commands, 3);
	
	delete buffer;
	delete memoryArray;
	delete device;
	delete physicalDevice;
	delete instance;
	
	return 0;
}

