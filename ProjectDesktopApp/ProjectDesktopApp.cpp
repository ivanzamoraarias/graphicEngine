// ProjectDesktopApp.cpp : Defines the entry point for the console application.
//
#include "stdafx.h";
#include "BUILD_ORDER.h"

VulkanInstance* instance;
VulkanPhysicalDevice* physicalDevice;


int main()
{
	VulkanConfiguration engineConfiguration;
	engineConfiguration.applicationName = "Vulkan App";
	engineConfiguration.applicationVersion = VK_MAKE_VERSION(1,0,0);

	instance = new VulkanInstance(engineConfiguration);

	physicalDevice = VulkanPhysicalDevice::getPhysicalDevice(instance);
	
	delete physicalDevice;
	delete instance;
	
	return 0;
}

