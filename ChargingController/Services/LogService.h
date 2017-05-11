#pragma once

#include "../Domain/Repository.h"
#include "../Services/ILogService.h"
#include <cmath>

class LogService : public ILogService
{
public:
	LogService(IRepository *repository);
	~LogService();
	void insertBatteryLog(int batteryId, float voltage, float current, float temp);
	void insertPanelLog(int panelId, float voltage, float current, float temp);
	void updateStatus();
	
private:
	IRepository *repository;

};

