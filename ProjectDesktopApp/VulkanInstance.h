#pragma once
#include "stdafx.h"
#include "VulkanConfiguration.h"
#include "Initializers.h"

class VulkanInstance
{
public:
	VulkanInstance(VulkanConfiguration& engineConfiguration);
	~VulkanInstance();
	VkInstance& getInstance();

private:
	VkInstance instance;
	std::vector<const char*> layers;
	std::vector<const char*> extensions;

};