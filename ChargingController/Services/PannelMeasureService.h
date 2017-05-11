#include "../INA219/INA219.h"
#include "../Services/IMeasureService.h"

class PannelMeasureService : public IMeasureService
{
	private:
		INA219 ina219Pannel;

	public:
		PannelMeasureService();
		float getVoltage();
		float getCurrent();
		float getTemperature();
};