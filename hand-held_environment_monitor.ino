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
#include <Console.h>
#include "SerialLog.h"
#include "yeelinkclient.h"
#include "hand-held_environment_monitor.h"

void setup() {
  LOG_PRINTLN("setup()");
#ifdef DEBUG
  Serial.begin(9600);
#endif

#ifndef NOT_USE_NETWORK
  initYeelinkClient();
#endif

#ifndef NOT_USE_OLED
  initOled128Display();//Due to resource limit, OLED and Network output should be seperated.
#endif
  initAirQualitySensor();
  initMQ2Sensor();
  initDHTSensor();
}

void loop() {
  LOG_PRINTLN("loop()");

#ifndef NOT_USE_OLED
  displaySampling();
#endif

  float sensorData[SENSOR_DATA_LEN];
  sensorData[AIRQ_DATA_INDEX] = getAQIFromAirQualitySensor();
  sensorData[DUST_DATA_INDEX] = getDustFromDustSensor();
  sensorData[CH4_DATA_INDEX] = getCH4FromMQ2Sensor();
  sensorData[HCHO_DATA_INDEX] = getHCHOFromHCHOSensor();
  sensorData[TEMPERATURE_DATA_INDEX] = getTemperatureFromDHTSensor();
  sensorData[HUMIDITY_DATA_INDEX] = getHumidityFromDHTSensor();

#ifndef NOT_USE_OLED
  displaySensorData(sensorData);
#endif

#ifndef NOT_USE_NETWORK
  sendSensorDataToYeelink(sensorData[AIRQ_DATA_INDEX], SENSOR_AIRQ_DATA_INDEX);//to consider removing from web
  sendSensorDataToYeelink(sensorData[HCHO_DATA_INDEX], SENSOR_HCHO_DATA_INDEX);
  sendSensorDataToYeelink(sensorData[DUST_DATA_INDEX], SENSOR_DUST_DATA_INDEX);
  sendSensorDataToYeelink(sensorData[CH4_DATA_INDEX], SENSOR_CH4_DATA_INDEX);
  sendSensorDataToYeelink(sensorData[TEMPERATURE_DATA_INDEX], SENSOR_CH4_DATA_INDEX);
  sendSensorDataToYeelink(sensorData[HUMIDITY_DATA_INDEX], SENSOR_HUMIDITY_DATA_INDEX);
#endif
  
  delay(10000);
  
}
