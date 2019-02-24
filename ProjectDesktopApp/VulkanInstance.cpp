#include "stdafx.h"
#include "VulkanInstance.h"
#include "Validation.h"

VulkanInstance::VulkanInstance(VulkanConfiguration & engineConfiguration)
{
	VkApplicationInfo applicationInfo = Initializers::getApplicationInfo(engineConfiguration);
	VkInstanceCreateInfo instanceInfo = Initializers::instanceCreateInfo(applicationInfo, layers, extensions);
	checkError(
		vkCreateInstance(&instanceInfo, NULL, &instance)
	);
}

VulkanInstance::~VulkanInstance()
{
	vkDestroyInstance(instance, NULL);
}

VkInstance & VulkanInstance::getInstance()
{
	return instance;
}
