#pragma once

#include "../INA219/INA219.h"

class BatteryMeasureService
{
	private:
		INA219 ina219Battery;

	public:
		BatteryMeasureService();
		float getVoltage();
		float getCurrent();
		float getTemperature();
};
