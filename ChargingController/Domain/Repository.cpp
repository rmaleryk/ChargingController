#include "Repository.h"


Repository::Repository()
{
	int query_state;

	mysql_init(&mysql);

	connection = mysql_real_connect(&mysql, "localhost", "root", "qwerty", "charging", 3306, 0, 0);

	if (connection == NULL)
	{
		std::cout << "MySQL_Error: " << mysql_error(&mysql) << std::endl;
	}

}


Repository::~Repository()
{
	// Destructor
}

void Repository::queryExecute(char* query)
{
	int queryResult = mysql_query(connection, query);

	if (queryResult != 0)
	{
		std::cout << "MySQL_Error: " << mysql_error(connection) << std::endl;
	}
}


