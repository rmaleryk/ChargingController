#ifndef CHARGINGCONTROLLER_H
#define CHARGINGCONTROLLER_H

#include <iostream>
#include <unistd.h>
#include <string>

// Include BlackLib BeagleBone Library

#include "BlackCore.h"
#include "BlackADC/BlackADC.h"
#include "BlackPWM/BlackPWM.h"
#include "BlackGPIO/BlackGPIO.h"
#include "BlackI2C/BlackI2C.h"

#include "Services/IMeasureService.h"
#include "Services/BatteryMeasureService.h"
#include "Services/PannelMeasureService.h"
#include "Services/PWMChargingService.h"
#include "Services/MySqlDBService.h"
#include "Services/NotificationService.h"

#include "Domain/LogRepository.h"
#include "Domain/Battery.h"
#include "Domain/Panel.h"
#include "Domain/BatteryRepository.h"
#include "Domain/PanelRepository.h"
#include "Domain/NotificationRepository.h"

#endif