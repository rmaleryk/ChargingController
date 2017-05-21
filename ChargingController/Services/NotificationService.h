#pragma once

#include "../Domain/Notification.h"
#include "../Domain/NotificationRepository.h"
#include "../Domain/Battery.h"
#include "../Domain/Panel.h"
#include <sstream>

class NotificationService
{
public:
	NotificationService(NotificationRepository *notificationRepository);
	~NotificationService();
	void checkingProcess(Battery *battery, Panel *panel);
	void startNotification();

private:
	NotificationRepository *notificationRepository;
	time_t lastTimeBatteryTemp;
	time_t lastTimePanelTemp;

	void batteryTemperatureChecking(Battery *battery);
	void panelTemperatureChecking(Panel *panel);

};

