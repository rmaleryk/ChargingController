#include "BatteryMeasureService.h"


BatteryMeasureService::BatteryMeasureService()
{
	ina219Battery = INA219(0x40, BlackLib::I2C_1);

	ina219Battery.begin();
	ina219Battery.setCalibration_32V_1A();

}

float BatteryMeasureService::getVoltage()
{
	return ina219Battery.getBusVoltage_V();
}

float BatteryMeasureService::getCurrent()
{
	return ina219Battery.getCurrent_mA();
}

float BatteryMeasureService::getTemperature()
{
	return 0;
}

