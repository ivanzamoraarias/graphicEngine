#pragma once
#include "stdafx.h"

//Engine Configuration
struct VulkanConfiguration
{
	const char* applicationName = "";
	uint32_t applicationVersion = VK_MAKE_VERSION(0, 0, 0);

	const char* engineName = "Graphics Engine";
	const uint32_t engineVersion = VK_MAKE_VERSION(0, 0, 0);
	const uint32_t apiVersion = VK_MAKE_VERSION(1, 1, 97);
};