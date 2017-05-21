#pragma once

#include <mysql/mysql.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "../Domain/Notification.h"
#include "../Services/MySqlDBService.h"

class NotificationRepository
{
public:
	NotificationRepository(MySqlDBService *mySqlDbService);
	~NotificationRepository();
	void sendNotification(Notification *notification);

private:
	MySqlDBService *mySqlDbService;

};

