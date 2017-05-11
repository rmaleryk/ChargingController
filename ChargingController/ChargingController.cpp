// Charging Contorller Main Source

#include "ChargingController.h"
#include <iostream>
#include <unistd.h>

int main(void)
{

	std::cout << "[ChargingController] Started" << std::endl;

	BatteryMeasureService *batteryMeasureService = new BatteryMeasureService;
	PannelMeasureService *pannelMeasureService = new PannelMeasureService;
	Repository *repository = new Repository;
	LogService *logService = new LogService(repository);

	int loopStep = 0;

	while (true)
	{
		
		float batteryVoltage = batteryMeasureService->getVoltage();
		float batteryCurrent = batteryMeasureService->getCurrent();
		float batteryTemp = batteryMeasureService->getTemperature();
		float pannelVoltage = pannelMeasureService->getVoltage();
		float pannelCurrent = pannelMeasureService->getCurrent();
		float pannelTemp = pannelMeasureService->getTemperature();


		std::cout << std::endl << "[Battery]: " << std::endl;
		std::cout << "voltage: " << batteryVoltage << std::endl;
		std::cout << "current: " << batteryCurrent * 0.001 << std::endl;
		std::cout << "temperature: " << batteryTemp << std::endl;

		std::cout << std::endl << "[Pannel]: " << std::endl;
		std::cout << "voltage: " << pannelVoltage << std::endl;
		std::cout << "current: " << pannelCurrent * 0.001 << std::endl;
		std::cout << "temperature: " << pannelTemp << std::endl;

		if (loopStep >= 10) // 1 time per 10 sec
		{
			// Push data to the DB
			logService->insertBatteryLog(1, batteryVoltage, batteryCurrent * 0.001, batteryTemp);
			logService->insertPanelLog(1, pannelVoltage, pannelCurrent * 0.001, pannelTemp);

			loopStep = 0;
		}

		// Delay
		usleep(1000000); // 1 sec
		loopStep++;

	}

	return 0;
}
