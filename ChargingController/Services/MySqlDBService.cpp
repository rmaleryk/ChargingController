#include "MySqlDBService.h"

MySqlDBService::MySqlDBService()
{

}


MySqlDBService::~MySqlDBService()
{
	// Destructor
}

MYSQL* MySqlDBService::connect()
{
	mysql_init(&mysql);

	connection = mysql_real_connect(&mysql, "localhost", "root", "qwerty", "charging", 3306, 0, 0);

	if (connection == NULL)
	{
		std::cout << "MySQL_Error: " << mysql_error(&mysql) << std::endl;
	}

	return connection;

}

void MySqlDBService::disconnect()
{
	mysql_close(connection);
}


