/*
 * This demo is an open source machine for detect air quality.
 * dust sensor
 * HCHO sensor
 * MQ2  sensor
 * air  sensor
*/
#include <Bridge.h>
#include <Console.h>
#include <FileIO.h>
#include <HttpClient.h>
#include <Mailbox.h>
#include <Process.h>
#include <YunClient.h>
#include <YunServer.h>

#include "yeelinkclient.h"

#define DIGIT_PIN_DUST_SENSOR 8
#define ANALOG_PIN_HQ2_SENSOR 0
#define ANALOG_PIN_HCHO_SENSOR 1
#define ANALOG_PIN_AIRQ_SENSOR 2
#define DUST_VALUE 0
#define HCHO_VALUE 1
#define AIRQ_VALUE 2
#define CO_VALUE 3
#define CH4_VALUE 4

float values[5];

void setup() {
  Serial.begin(9600);
  initOled128Display();
  initAirQualitySensor();
  //dust_sensor_init();
  //mq2_sensor_init();
  //network_init();
  clientInit();
}

void loop() {
  
  displaySapmlling();
  
  values[DUST_VALUE] = dust_sensor_execute(DIGIT_PIN_DUST_SENSOR);
  Serial.print("concentration = ");
  Serial.print(values[DUST_VALUE]);
  Serial.println(" pcs/0.01cf");
  Serial.println("\n");
  //  hcho_sensor_execute();
  //  values[HCHO_VALUE] = 0;
  //  Serial.print("HCHO ppm = ");
  //  Serial.print(values[HCHO_VALUE]);
  //  Serial.println("\n");
  //mq2_sensor_execute();
  //  values[CO_VALUE] = 0;
  //  Serial.print("CO ppm= ");
  //  Serial.print(values[CO_VALUE]);
  //  Serial.println("\n");
  //  values[CH4_VALUE] = 0;
  //  Serial.print("CH4 ppm= ");
  //  Serial.print(values[CH4_VALUE]);
  //  Serial.println("\n");
  //  values[AIRQ_VALUE] = airQuality_sensor_execute();
  //  values[AIRQ_VALUE] = 0;
  //  Serial.print("AIRQ = ");
  //  Serial.print(values[AIRQ_VALUE]);
  //  Serial.println("\n");
  //oled128_display_execute();

  int airQuality = getSensorValueFromAirQualitySensor();
  Serial.print("airQuality=" + (String)airQuality);
  displayAnalysisResult(airQuality, 200, 0, 0, 0);  //air,dust,hcho,co,ch4

  curlPostData(values[0], SENSOR_1);
  curlPostData(values[1], SENSOR_2);
  curlPostData(values[2], SENSOR_3);
  curlPostData(values[3], SENSOR_4);
  curlPostData(values[4], SENSOR_5);
  delay(1000 * 30);
  //network_execute();
}

