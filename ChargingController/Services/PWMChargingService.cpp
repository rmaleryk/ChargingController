#include "PWMChargingService.h"

PWMChargingService::PWMChargingService(BatteryMeasureService *batteryMeasureService, BlackLib::BlackPWM *pwmHandler, Battery *battery)
{
	this->batteryMeasureService = batteryMeasureService;
	this->pwmHandler = pwmHandler;
	this->battery = battery;

	this->pwmHandler->setPeriodTime(40, BlackLib::timeType::microsecond); // 40 us = 25 kHz
	this->pwmValue = 0;
}


PWMChargingService::~PWMChargingService()
{
	pwmHandler->setDutyPercent(0);
}

int PWMChargingService::chargingProcess()
{
	int result = 0;
	float batteryVoltage = batteryMeasureService->getVoltage();
	float batteryCurrent = batteryMeasureService->getCurrent() * 0.001;

	if (batteryVoltage < battery->maxVoltage) // Voltage Bound []
	{
		if (batteryCurrent < battery->maxCurrent) // Current Bound [0.31-0.35 A]
		{
			if (pwmValue < 100) // Max 100 %
			{
				pwmValue++;
				result = 1;
			}
		}
		else
		{
			if (pwmValue > 0) // Only positive i
			{
				pwmValue--;
				result = -1;
			}
		}
	}
	else
	{
		// Reset PWM
		pwmValue = 0;
		result = 0;
	}

	pwmHandler->setDutyPercent(pwmValue);
	std::cout << pwmValue << std::endl;
	return result;
}
