#include "LogRepository.h"


LogRepository::LogRepository(MySqlDBService *mySqlDbService)
{
	this->mySqlDbService = mySqlDbService;
}


LogRepository::~LogRepository()
{
	// Destructor
}

void LogRepository::queryExecute(char* query)
{
	MYSQL *connection;

	connection = mySqlDbService->connect();

	int queryResult = mysql_query(connection, query);

	if (queryResult != 0)
	{
		std::cout << "MySQL_Error: " << mysql_error(connection) << std::endl;
	}

	mySqlDbService->disconnect();
}

void LogRepository::updateStatus()
{
	char query[300];
	sprintf(query, "UPDATE `status` SET `power` = 1;");
	this->queryExecute(query);
}

void LogRepository::insertBatteryLog(int batteryId, float voltage, float current, float temp)
{
	char query[300];
	sprintf(query, "INSERT INTO `cc_battery_logs` (`battery_id`, `time`, `voltage`, `current`, `temperature`) VALUES (%d, NOW(), %.2f, %.2f, %.2f);", batteryId, voltage, std::abs(current), temp);
	this->queryExecute(query);
}

void LogRepository::insertPanelLog(int panelId, float voltage, float current, float temp)
{
	char query[300];
	sprintf(query, "INSERT INTO `cc_panel_logs` (`panel_id`, `time`, `voltage`, `current`, `temperature`) VALUES (%d, NOW(), %.2f, %.2f, %.2f);", panelId, voltage, std::abs(current), temp);
	this->queryExecute(query);
}


