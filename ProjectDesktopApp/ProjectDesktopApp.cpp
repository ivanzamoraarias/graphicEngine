// ProjectDesktopApp.cpp : Defines the entry point for the console application.
//
#include "stdafx.h";
#include "BUILD_ORDER.h"

VulkanInstance* instance;
VulkanPhysicalDevice* physicalDevice;
VulkanDevice* device; 

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

	device->FreeComputeCommand(commands, 3);
	
	delete device;
	delete physicalDevice;
	delete instance;
	
	return 0;
}

