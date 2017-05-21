#pragma once

#include <mysql/mysql.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
#include <sstream>
#include "../Domain/Panel.h"
#include "../Services/MySqlDBService.h"

class PanelRepository
{
public:
	PanelRepository(MySqlDBService *mySqlDbService);
	~PanelRepository();
	Panel* getPanelById(int panelId);

private:
	MySqlDBService *mySqlDbService;

};

