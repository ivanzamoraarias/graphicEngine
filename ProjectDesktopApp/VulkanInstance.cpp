#include "stdafx.h"
#include "VulkanInstance.h"
#include "Validation.h"

VulkanInstance::VulkanInstance(VulkanConfiguration & engineConfiguration)
{
	layers.push_back("VK_LAYER_LUNARG_standard_validation");
	extensions.push_back("VK_EXT_debug_report");

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
