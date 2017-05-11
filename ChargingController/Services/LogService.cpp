#include "LogService.h"


LogService::LogService(IRepository *repository)
{
	this->repository = repository;
}


LogService::~LogService()
{
}

void LogService::updateStatus()
{
	char query[300];
	sprintf(query, "UPDATE `status` SET `power` = 1;");
	repository->queryExecute(query);
}

void LogService::insertBatteryLog(int batteryId, float voltage, float current, float temp)
{
	char query[300];
	sprintf(query, "INSERT INTO `cc_battery_logs` (`battery_id`, `time`, `voltage`, `current`, `temperature`) VALUES (%d, NOW(), %.2f, %.2f, %.2f);", batteryId, voltage, std::abs(current), temp);
	repository->queryExecute(query);
}

void LogService::insertPanelLog(int panelId, float voltage, float current, float temp)
{
	char query[300];
	sprintf(query, "INSERT INTO `cc_panel_logs` (`panel_id`, `time`, `voltage`, `current`, `temperature`) VALUES (%d, NOW(), %.2f, %.2f, %.2f);", panelId, voltage, std::abs(current), temp);
	repository->queryExecute(query);
}
