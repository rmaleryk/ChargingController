#pragma once

#include "../Domain/Repository.h"
#include <cmath>

class LogService
{
public:
	LogService(Repository *repository);
	~LogService();
	void insertBatteryLog(int batteryId, float voltage, float current, float temp);
	void insertPanelLog(int panelId, float voltage, float current, float temp);
	void updateStatus();
	
private:
	Repository *repository;

};

