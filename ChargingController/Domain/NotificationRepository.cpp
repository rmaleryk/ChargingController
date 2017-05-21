#include "NotificationRepository.h"

NotificationRepository::NotificationRepository(MySqlDBService *mySqlDbService)
{
	this->mySqlDbService = mySqlDbService;
}


NotificationRepository::~NotificationRepository()
{
	// Destructor
}

void NotificationRepository::sendNotification(Notification *notification)
{
	MYSQL_RES *res;
	MYSQL_ROW row;
	MYSQL_FIELD *field;
	MYSQL *connection;

	connection = mySqlDbService->connect();

	std::stringstream ss;
	ss << "INSERT INTO cc_logs (text, type) VALUES (\"" << notification->text << "\", " << notification->type << ");";
	mysql_query(connection, ss.str().c_str());

	res = mysql_store_result(connection);

	if (res != NULL)
		mysql_free_result(res);

	mySqlDbService->disconnect();

}


