// Charging Contorller Main Source

#include "ChargingController.h"
#include <iostream>

int main(void)
{

	std::cout << "[ChargingController] Started" << std::endl;
	
	BlackLib::BlackGPIO led1(BlackLib::GPIO_24, BlackLib::output, BlackLib::FastMode);
	led1.setValue(BlackLib::high);

	while (1)
	{
		// Charging algorithm

	}

	return 0;
}