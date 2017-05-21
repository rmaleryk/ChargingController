#include "PanelRepository.h"

PanelRepository::PanelRepository(MySqlDBService *mySqlDbService)
{
	this->mySqlDbService = mySqlDbService;
}


PanelRepository::~PanelRepository()
{
	// Destructor
}

Panel* PanelRepository::getPanelById(int panelId)
{
	MYSQL_RES *res;
	MYSQL_ROW row;
	MYSQL_FIELD *field;
	MYSQL *connection;
	Panel *panel = new Panel;

	connection = mySqlDbService->connect();

	std::stringstream ss;
	ss << "SELECT * FROM cc_panels WHERE id = " << panelId << ";";
	mysql_query(connection, ss.str().c_str());

	res = mysql_store_result(connection);

	// Create associative massive of column names
	std::map<std::string, int> columns;
	int i = 0;
	while (field = mysql_fetch_field(res)) {
		columns.insert(std::pair<std::string, int>(field->name, i++));
	}

	row = mysql_fetch_row(res);

	panel->maxVoltage = atof(row[columns["max_voltage"]]);
	panel->maxCurrent = atof(row[columns["max_current"]]);
	panel->maxTemperature = atof(row[columns["max_temperature"]]);
	panel->minTemperature = atof(row[columns["min_temperature"]]);
	panel->square = atof(row[columns["square"]]);
	panel->power = atof(row[columns["power"]]);

	if (res != NULL)
		mysql_free_result(res);

	mySqlDbService->disconnect();
	
	return panel;
}


