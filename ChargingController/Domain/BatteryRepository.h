#pragma once

#include <mysql/mysql.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
#include <sstream>
#include "../Domain/Battery.h"
#include "../Services/MySqlDBService.h"

class BatteryRepository
{
public:
	BatteryRepository(MySqlDBService *mySqlDbService);
	~BatteryRepository();
	Battery* getBatteryById(int batteryId);

private:
	MySqlDBService *mySqlDbService;

};

