#include "stdafx.h"
#include "Initializers.h"

VkApplicationInfo Initializers::getApplicationInfo(VulkanConfiguration& config)
{
	VkApplicationInfo info = {};
	info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	info.pApplicationName = config.applicationName;
	info.pEngineName = config.engineName;
	info.applicationVersion = config.applicationVersion;
	info.engineVersion = config.engineVersion;
	info.apiVersion = config.apiVersion;

	return info;
}

VkInstanceCreateInfo Initializers::instanceCreateInfo(VkApplicationInfo& appInfo, std::vector<const char*>& layers, std::vector<const char*>& extensions)
{
	VkInstanceCreateInfo info = {};
	info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	info.pApplicationInfo = &appInfo;
	info.enabledExtensionCount = extensions.size();
	info.enabledLayerCount = extensions.size();
	info.ppEnabledExtensionNames = extensions.data();
	info.ppEnabledLayerNames = layers.data();
	return info;
}