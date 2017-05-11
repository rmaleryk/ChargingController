#pragma once

class ILogService
{
public:
	virtual void insertBatteryLog(int batteryId, float voltage, float current, float temp) = 0;
	virtual void insertPanelLog(int panelId, float voltage, float current, float temp) = 0;
	virtual void updateStatus() = 0;

};
