#ifndef YEE_LINK_CLIENT
#define YEE_LINK_CLENT
#include <Arduino.h>

#define API_KEY "6259afea8328804a22589aa3c8267512"
#define API_VERSION "v1.0"

#define DEVICE_ID "340732"//空气质量检测器
#define SENSOR_1 "377542"//Air quality
#define SENSOR_2 "377543"//CO
#define SENSOR_3 "377544"//HCHO
#define SENSOR_4 "377545"//Dust
#define SENSOR_5 "377887"//CH4

void clientInit();

void curlPostData(float dataParam, String sensorId, String deviceId = DEVICE_ID);

#endif
