#pragma once

class IMeasureService
{
public:
	virtual float getVoltage() = 0;
	virtual float getCurrent() = 0;
	virtual float getTemperature() = 0;
};
