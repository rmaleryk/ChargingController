#include "BatteryRepository.h"

BatteryRepository::BatteryRepository(MySqlDBService *mySqlDbService)
{
	this->mySqlDbService = mySqlDbService;
}


BatteryRepository::~BatteryRepository()
{
	// Destructor
}

Battery* BatteryRepository::getBatteryById(int batteryId)
{
	MYSQL_RES *res;
	MYSQL_ROW row;
	MYSQL_FIELD *field;
	MYSQL *connection;
	Battery *battery = new Battery;

	connection = mySqlDbService->connect();

	std::stringstream ss;
	ss << "SELECT * FROM cc_batteries WHERE id = " << batteryId << ";";
	mysql_query(connection, ss.str().c_str());

	res = mysql_store_result(connection);

	// Create associative massive of column names
	std::map<std::string, int> columns;
	int i = 0;
	while (field = mysql_fetch_field(res)) {
		columns.insert(std::pair<std::string, int>(field->name, i++));
	}

	row = mysql_fetch_row(res);

	battery->maxVoltage = atof(row[columns["max_voltage"]]);
	battery->maxCurrent = atof(row[columns["max_current"]]);
	battery->maxTemperature = atof(row[columns["max_temperature"]]);
	battery->minTemperature = atof(row[columns["min_temperature"]]);
	battery->capacity = atof(row[columns["capacity"]]);

	if (res != NULL)
		mysql_free_result(res);

	mySqlDbService->disconnect();
	
	return battery;
}


