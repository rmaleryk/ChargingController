// Charging Contorller Main Source

#include "ChargingController.h"

int main(void)
{

	BatteryMeasureService *batteryMeasureService = new BatteryMeasureService;
	IMeasureService *pannelMeasureService = new PannelMeasureService;
	
	MySqlDBService *mySqlDbService = new MySqlDBService;
	LogRepository *logRepository = new LogRepository(mySqlDbService);

	Battery *battery = new Battery;
	BatteryRepository *batteryRepository = new BatteryRepository(mySqlDbService);
	battery = batteryRepository->getBatteryById(1);
	
	Panel *panel = new Panel;
	PanelRepository *panelRepository = new PanelRepository(mySqlDbService);
	panel = panelRepository->getPanelById(1);
	
	BlackLib::BlackPWM *pwmHandler = new BlackLib::BlackPWM(BlackLib::EHRPWM2A); // P8_19
	IChargingService *chargingService = new PWMChargingService(batteryMeasureService, pwmHandler, battery);

	int loopStep = 0;
	int stepResult = 0;

	std::cout << "[ChargingController] Started" << std::endl;

	while (true)
	{
		// Fill the model of battery and panel
		battery->voltage = batteryMeasureService->getVoltage();
		battery->current = batteryMeasureService->getCurrent() * 0.001;
		battery->temperature = -20;//batteryMeasureService->getTemperature();
		panel->voltage = pannelMeasureService->getVoltage();
		panel->current = pannelMeasureService->getCurrent() * 0.001;
		panel->temperature = -15; //pannelMeasureService->getTemperature();


		std::cout << std::endl << "[Battery]: ";
		std::cout << battery->voltage << " V; ";
		std::cout << battery->current << " A; ";
		std::cout << battery->temperature << " C" << std::endl;

		std::cout << std::endl << "[Pannel]: ";
		std::cout << panel->voltage << " V; ";
		std::cout << panel->current << " A; ";
		std::cout << panel->temperature << " C" << std::endl;

		// Start Charging
		stepResult = chargingService->chargingProcess();

		float percent = 1 - (std::stof(pwmHandler->getDutyValue()) / std::stof(pwmHandler->getPeriodValue()));
		std::cout << "[PWM]: " << stepResult << "; " << percent * 100 << "%" << std::endl;


		if (loopStep >= 10) // 1 time per 10 sec
		{
			// Push data to the DB
			logRepository->insertBatteryLog(1, battery->voltage, battery->current, battery->temperature);
			logRepository->insertPanelLog(1, panel->voltage, panel->current, panel->temperature);
			std::cout << "[LogService]: Data was sent" << std::endl;
			loopStep = 0;
		}

		// Delay
		usleep(1000000); // 1 sec
		loopStep++;

	}

	return 0;
}
