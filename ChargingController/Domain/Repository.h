#pragma once

#include <mysql/mysql.h>
#include <iostream>
#include <stdio.h>
#include "../Domain/IRepository.h"

class Repository : public IRepository
{
public:
	Repository();
	~Repository();
	void queryExecute(char* query);

private:
	MYSQL *connection, mysql;

};

