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

#define MQ2_SENSOR_ANALOG_PIN 0
#define HCHO_SENSOR_ANALOG_PIN 1
#define AIRQ_SENSOR_ANALOG_PIN 2
#define DUST_SENSOR_DIGITAL_PIN 8
#define DHT_SENSOR_DIGITAL_PIN 2

#define DUST_VALUE_INDEX 0
#define HCHO_VALUE_INDEX 1
#define AIRQ_VALUE_INDEX 2
#define CO_VALUE_INDEX 3
#define CH4_VALUE_INDEX 4
#define TEMPERATURE_VALUE_INDEX 5
#define HUMIDITY_VALUE_INDEX 6

float sensorValues[7];
float MQ2_R0;

void setup() {
  clientInit();
  Console.begin();
  initOled128Display();
  initAirQualitySensor();
  initMQ2Sensor();
  initHchoSensor();
  initDHTSensor();
}

void loop() {

  //displaySapmlling();

  sensorValues[AIRQ_VALUE_INDEX] = getSensorValueFromAirQualitySensor(AIRQ_SENSOR_ANALOG_PIN);
  sensorValues[DUST_VALUE_INDEX] = dust_sensor_execute(DUST_SENSOR_DIGITAL_PIN);
  sensorValues[CH4_VALUE_INDEX] = mq2_sensor_execute(MQ2_SENSOR_ANALOG_PIN);
  sensorValues[HCHO_VALUE_INDEX] = hcho_sensor_execute(HCHO_SENSOR_ANALOG_PIN);
  sensorValues[TEMPERATURE_VALUE_INDEX] = getTemperatureFromDHTSensor();
  sensorValues[HUMIDITY_VALUE_INDEX] = getHumidityFromDHTSensor();
  
  // TODO this method needs to refactor @FengWei
//  displayAnalysisResult(sensorValues[AIRQ_VALUE_INDEX],
//                        sensorValues[DUST_VALUE_INDEX],
//                        sensorValues[HCHO_VALUE_INDEX],
//                        sensorValues[CO_VALUE_INDEX],
//                        sensorValues[CH4_VALUE_INDEX]);

  curlPostData(sensorValues[AIRQ_VALUE_INDEX], SENSOR_1);
  //curlPostData(sensorValues[CO_VALUE_INDEX], SENSOR_2);
  curlPostData(sensorValues[HCHO_VALUE_INDEX], SENSOR_3);
  curlPostData(sensorValues[DUST_VALUE_INDEX], SENSOR_4);
  curlPostData(sensorValues[CH4_VALUE_INDEX], SENSOR_5);

}


