#pragma once

#include <mysql/mysql.h>
#include <iostream>
#include <stdio.h>

class Repository
{
public:
	Repository();
	~Repository();
	void queryExecute(char* query);

private:
	MYSQL *connection, mysql;

};

