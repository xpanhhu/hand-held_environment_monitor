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
#include <Process.h>
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

#define SENSOR_DUST_VALUE_INDEX "377545"//Dust
#define SENSOR_HCHO_VALUE_INDEX "377544"//HCHO
#define SENSOR_AIRQ_VALUE_INDEX "377542"//Air quality
#define SENSOR_CH4_VALUE_INDEX "377887"//CH4
#define SENSOR_TEMPERATURE_VALUE_INDEX "377543"//Temperature
#define SENSOR_HUMIDITY_VALUE_INDEX "377933" //Humidity


void setup() {
  clientInit();
  initOled128Display();//Due to resource limit, OLED and Network output should be seperated.
  initAirQualitySensor();
  initMQ2Sensor();
  initDHTSensor();
}

void loop() {
  float sensorValues[6];
  displaySampling();

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
  curlPostData(sensorValues[TEMPERATURE_VALUE_INDEX], SENSOR_TEMPERATURE_VALUE_INDEX);
  curlPostData(sensorValues[HUMIDITY_VALUE_INDEX], SENSOR_HUMIDITY_VALUE_INDEX);

  delay(10000);
}

