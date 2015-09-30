#ifndef YEE_LINK_CLIENT
#define YEE_LINK_CLENT
#include <Arduino.h>

#define API_KEY "6259afea8328804a22589aa3c8267512"
#define API_VERSION "v1.0"

#define DEVICE_ID "340732"
#define SENSOR_1 "377542"
#define SENSOR_2 "377543"
#define SENSOR_3 "377544"
#define SENSOR_4 "377545"
#define SENSOR_5 "377546"

void clientInit();

void curlPostData(float dataParam, String sensorId, String deviceId=DEVICE_ID);

#endif
