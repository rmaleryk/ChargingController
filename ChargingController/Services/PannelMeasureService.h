#include "../INA219/INA219.h"

class PannelMeasureService
{
	private:
		INA219 ina219Pannel;

	public:
		PannelMeasureService();
		float getVoltage();
		float getCurrent();
		float getTemperature();
};