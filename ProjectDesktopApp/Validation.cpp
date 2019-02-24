#include "stdafx.h"
#include "Validation.h"

void checkError(VkResult result)
{
	if(result != VK_SUCCESS) {
		std::cout << "Error: No Success in VK Operation" << std::endl;
		assert(0 && "Error on VK Operation");
	}
}
