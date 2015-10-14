#ifndef YEE_LINK_CLIENT
#define YEE_LINK_CLENT
#include <Arduino.h>

#define API_KEY "6259afea8328804a22589aa3c8267512"
#define API_VERSION "v1.0"

#define DEVICE_ID "340732"//hand-held_environment_monitor

// Comment out the CONSOLE DEBUG if need to close debug log
#define CONSOLE_ENABLED

#ifdef CONSOLE_ENABLED
#define CONSOLE_PRINT(str)\
  Console.print(str)
#define CONSOLE_PRINTLN(str)\
  Console.println(str)
#define CONSOLE_FLUSH()\
  Console.flush()
#else
#define CONSOLE_PRINT(str)
#define CONSOLE_PRINTLN(str)
#define CONSOLE_FLUSH()
#endif

void initYeelinkClient();

void sendSensorDataToYeelink(float dataParam, String sensorId, String deviceId = DEVICE_ID);

String getSensorDataFromYeelink(String key, String sensorId, String deviceId = DEVICE_ID);

#endif
