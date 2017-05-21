#include "NotificationService.h"


NotificationService::NotificationService(NotificationRepository *notificationRepository)
{
	this->notificationRepository = notificationRepository;
}


NotificationService::~NotificationService()
{
}

void NotificationService::startNotification()
{
	Notification *notification = new Notification;
	notification->type = Notification::INFO;
	std::stringstream message;
	message << "Charging process is started.";
	notification->text = message.str();
	notificationRepository->sendNotification(notification);
}

void NotificationService::checkingProcess(Battery *battery, Panel *panel)
{	
	this->batteryTemperatureChecking(battery);
	this->panelTemperatureChecking(panel);
}

void NotificationService::batteryTemperatureChecking(Battery *battery)
{
	time_t now = time(NULL);

	if (battery->temperature >= battery->maxTemperature || battery->temperature <= battery->minTemperature)
	{

		if (now >= lastTimeBatteryTemp + 300)
		{
			Notification *notification = new Notification;
			notification->type = Notification::DANGER;
			std::stringstream message;
			message << "Critical battery temperature: " << battery->temperature << "C!<br>Charging is stopped.";
			notification->text = message.str();
			notificationRepository->sendNotification(notification);

			std::cout << "[Notification]: " << message.str();

			lastTimeBatteryTemp = now;
		}
	}
}

void NotificationService::panelTemperatureChecking(Panel *panel)
{
	time_t now = time(NULL);

	if (now >= lastTimePanelTemp + 300)
	{
		if (panel->temperature >= panel->maxTemperature || panel->temperature <= panel->minTemperature)
		{
			Notification *notification = new Notification;
			notification->type = Notification::DANGER;
			std::stringstream message;
			message << "Critical panel temperature: " << panel->temperature << "C!";
			notification->text = message.str();
			notificationRepository->sendNotification(notification);

			std::cout << "[Notification]: " << message.str();

			lastTimePanelTemp = now;
		}
	}

}


