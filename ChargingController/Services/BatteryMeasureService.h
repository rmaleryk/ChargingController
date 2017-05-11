#pragma once

#include "../INA219/INA219.h"
#include "../Services/IMeasureService.h"

class BatteryMeasureService : public IMeasureService
{
	private:
		INA219 ina219Battery;

	public:
		BatteryMeasureService();
		float getVoltage();
		float getCurrent();
		float getTemperature();
};
