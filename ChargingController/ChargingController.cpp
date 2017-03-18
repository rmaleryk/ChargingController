// Charging Contorller Main Source

#include "ChargingController.h"
#include "INA219/INA219.h"
#include <iostream>
#include <unistd.h>


int main(void)
{

	std::cout << "[ChargingController] Started" << std::endl;

	INA219 ina219;

	ina219.begin();
	ina219.setCalibration_16V_400mA();

	while(true)
	{
		// Charging algorithm

		float shuntvoltage = 0;
		float busvoltage = 0;
		float current_mA = 0;
		float loadvoltage = 0;

		shuntvoltage = ina219.getShuntVoltage_mV();
		busvoltage = ina219.getBusVoltage_V();
		current_mA = ina219.getCurrent_mA();
		loadvoltage = busvoltage + (shuntvoltage / 1000);



		std::cout << std::endl << "bus: " << busvoltage << std::endl;
		std::cout << "shuntvoltage: " << shuntvoltage << std::endl;
		std::cout << "current_mA: " << current_mA * 0.001 << std::endl;
		std::cout << "loadvoltage: " << loadvoltage << std::endl;

		usleep(2000);

	}

	return 0;
}