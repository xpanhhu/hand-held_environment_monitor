#ifndef YEE_LINK_CLIENT
#define YEE_LINK_CLENT
#include <Arduino.h>

#define API_KEY "6259afea8328804a22589aa3c8267512"
#define API_VERSION "v1.0"

#define DEVICE_ID "340732"//hand-held_environment_monitor

// Comment out the CONSOLE DEBUG if need to close debug log
//#define CONSOLE_ENABLED

void initYeelinkClient();

void sendSensorDataToYeelink(float dataParam, String sensorId, String deviceId = DEVICE_ID);

float getSensorDataFromYeelink(String key, String sensorId, String deviceId = DEVICE_ID);

#endif
