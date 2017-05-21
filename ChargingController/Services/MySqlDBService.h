#pragma once

#include <mysql/mysql.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class MySqlDBService
{
public:
	MySqlDBService();
	~MySqlDBService();
	MYSQL* connect();
	void disconnect();

private:
	MYSQL *connection, mysql;

};

