#pragma once

#include "../BlackPWM/BlackPWM.h"
#include "../Services/BatteryMeasureService.h"
#include "../Services/IChargingService.h"
#include "../Domain/Battery.h"

class PWMChargingService : public IChargingService
{
public:
	PWMChargingService(BatteryMeasureService *batteryMeasureService, BlackLib::BlackPWM *pwmHandler, Battery *battery);
	~PWMChargingService();
	int chargingProcess();


private:
	BatteryMeasureService *batteryMeasureService;
	BlackLib::BlackPWM *pwmHandler;
	Battery *battery;
	int pwmValue;

};

