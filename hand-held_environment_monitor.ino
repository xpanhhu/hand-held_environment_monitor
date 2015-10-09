/*
 * This demo is an open source machine for monitoring multi air indicator and environment data, and shows in both way: local OLED and Web.
 * Dust Sensor
 * HCHO sensor
 * MQ2  Gas Sensor
 * Air  Quality Sensor
 * Temperature&Humidity Sensor
 * 
 *  Written September 2015
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

#define MQ2_SENSOR_ANALOG_PIN 'A0'
#define HCHO_SENSOR_ANALOG_PIN 'A1'
#define AIRQ_SENSOR_ANALOG_PIN 'A2'

#define DHT_SENSOR_DIGITAL_PIN 2
#define DUST_SENSOR_DIGITAL_PIN 8

#define DUST_VALUE_INDEX 0
#define HCHO_VALUE_INDEX 1
#define AIRQ_VALUE_INDEX 2
#define CH4_VALUE_INDEX 3
#define TEMPERATURE_VALUE_INDEX 4
#define HUMIDITY_VALUE_INDEX 5

float sensorValues[6];
float MQ2_R0;

void setup() {
  clientInit();
  Console.begin();
  //initOled128Display();//Due to resource limit, OLED and Network output should be seperated. 
  initAirQualitySensor();
  initMQ2Sensor();
  initHCHOSensor();
  initDHTSensor();
}

void loop() {

  //displaySapmlling();

  sensorValues[AIRQ_VALUE_INDEX] = getSensorValueFromAirQualitySensor();
  sensorValues[DUST_VALUE_INDEX] = dust_sensor_execute();
  sensorValues[CH4_VALUE_INDEX] = mq2_sensor_execute();
  sensorValues[HCHO_VALUE_INDEX] = HCHO_sensor_execute();
  sensorValues[TEMPERATURE_VALUE_INDEX] = getTemperatureFromDHTSensor();
  sensorValues[HUMIDITY_VALUE_INDEX] = getHumidityFromDHTSensor();
  
  // TODO this method needs to refactor @FengWei
//  displayAnalysisResult(sensorValues[AIRQ_VALUE_INDEX],
//                        sensorValues[DUST_VALUE_INDEX],
//                        sensorValues[HCHO_VALUE_INDEX],
//                        sensorValues[CH4_VALUE_INDEX]);

//  curlPostData(sensorValues[AIRQ_VALUE_INDEX], SENSOR_1);
//  curlPostData(sensorValues[HCHO_VALUE_INDEX], SENSOR_3);
//  curlPostData(sensorValues[DUST_VALUE_INDEX], SENSOR_4);
//  curlPostData(sensorValues[CH4_VALUE_INDEX], SENSOR_5);
  
  delay(10000);
}


