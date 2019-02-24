// ProjectDesktopApp.cpp : Defines the entry point for the console application.
//
#include "stdafx.h";
#include "Initializers.h"
#include "Validation.h"

#include "VulkanInstance.h"

VulkanInstance* instance;


int main()
{
	VulkanConfiguration engineConfiguration;
	engineConfiguration.applicationName = "Vulkan App";
	engineConfiguration.applicationVersion = VK_MAKE_VERSION(1,0,0);

	instance = new VulkanInstance(engineConfiguration);
	
	delete instance;
	
	return 0;
}

