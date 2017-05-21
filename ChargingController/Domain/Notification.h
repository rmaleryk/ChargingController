#pragma once

#include <string>

class Notification
{

public:
	enum NotificationType { INFO = 1, WARN, DANGER };

	std::string text;
	NotificationType type;

};