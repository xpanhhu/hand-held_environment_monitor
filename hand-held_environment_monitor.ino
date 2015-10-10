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
#ifdef DEBUG
  Serial.begin(9600);
#endif
  clientInit();
  initOled128Display();//Due to resource limit, OLED and Network output should be seperated.
  initAirQualitySensor();
  initMQ2Sensor();
  initDHTSensor();
}

void loop() {
  LOG_PRINTLN("loop()");

  displaySampling();

  float sensorValues[SENSOR_VALUES_LEN];
  sensorValues[AIRQ_VALUE_INDEX] = getSensorValueFromAirQualitySensor();
  sensorValues[DUST_VALUE_INDEX] = dust_sensor_execute();
  sensorValues[CH4_VALUE_INDEX] = mq2_sensor_execute();
  sensorValues[HCHO_VALUE_INDEX] = HCHO_sensor_execute();
  sensorValues[TEMPERATURE_VALUE_INDEX] = getTemperatureFromDHTSensor();
  sensorValues[HUMIDITY_VALUE_INDEX] = getHumidityFromDHTSensor();

  displayAnalysisResult(sensorValues[AIRQ_VALUE_INDEX],
                        sensorValues[DUST_VALUE_INDEX],
                        sensorValues[HCHO_VALUE_INDEX],
                        sensorValues[CH4_VALUE_INDEX],
                        sensorValues[TEMPERATURE_VALUE_INDEX],
                        sensorValues[HUMIDITY_VALUE_INDEX]);

  displaySampling();

  curlPostData(sensorValues[AIRQ_VALUE_INDEX], SENSOR_AIRQ_VALUE_INDEX);//to consider removing from web
  curlPostData(sensorValues[HCHO_VALUE_INDEX], SENSOR_HCHO_VALUE_INDEX);
  curlPostData(sensorValues[DUST_VALUE_INDEX], SENSOR_DUST_VALUE_INDEX);
  curlPostData(sensorValues[CH4_VALUE_INDEX], SENSOR_CH4_VALUE_INDEX);
  curlPostData(sensorValues[TEMPERATURE_VALUE_INDEX], SENSOR_CH4_VALUE_INDEX);
  curlPostData(sensorValues[HUMIDITY_VALUE_INDEX], SENSOR_HUMIDITY_VALUE_INDEX);
  
  delay(10000);
}
