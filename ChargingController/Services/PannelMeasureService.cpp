#include "PannelMeasureService.h"

PannelMeasureService::PannelMeasureService()
{
	ina219Pannel = INA219(0x41, BlackLib::I2C_1);

	ina219Pannel.begin();
	ina219Pannel.setCalibration_32V_1A();

}

float PannelMeasureService::getVoltage()
{
	return ina219Pannel.getBusVoltage_V();
}

float PannelMeasureService::getCurrent()
{
	return ina219Pannel.getCurrent_mA();
}

float PannelMeasureService::getTemperature()
{
	return 0;
}

