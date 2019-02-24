#pragma once
#include "stdafx.h";
#include "VulkanConfiguration.h";

namespace Initializers {
	VkApplicationInfo getApplicationInfo(VulkanConfiguration& config);
	VkInstanceCreateInfo instanceCreateInfo(VkApplicationInfo& appInfo, std::vector<const char*>& layers, std::vector<const char*>& extensions);
}