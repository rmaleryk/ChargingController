#pragma once

#include <mysql/mysql.h>
#include <iostream>
#include <stdio.h>
#include <cmath>
#include "../Domain/IRepository.h"
#include "../Services/MySqlDBService.h"

class LogRepository
{
public:
	LogRepository(MySqlDBService *mySqlDbService);
	~LogRepository();
	void insertBatteryLog(int batteryId, float voltage, float current, float temp);
	void insertPanelLog(int panelId, float voltage, float current, float temp);
	void updateStatus();

private:
	void queryExecute(char* query);
	MySqlDBService *mySqlDbService;

};

