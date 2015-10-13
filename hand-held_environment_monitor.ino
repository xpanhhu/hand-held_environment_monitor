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
#include "MemoryFree.h"
#include "yeelinkclient.h"
#include "hand-held_environment_monitor.h"

void setup() {
#ifdef SERIAL_LOG_ENABLE
  Serial.begin(9600);
  LOG_PRINTLN("setup()");
#endif
#ifdef NETWORK_ENABLED
  initYeelinkClient();
#endif
#ifdef OLED_ENABLED
  initOled128Display();
#endif
#ifdef AIRQ_SENSOR_ENABLED
  initAirQualitySensor();
#endif
#ifdef MQ2_SENSOR_ENABLED
  initMQ2Sensor();
#endif
#ifdef DHT_SENSOR_ENABLED
  initDHTSensor();
#endif
#ifdef BUZZER_ENABLED
  initBuzzer();
#endif
}

void loop() {
  LOG_PRINTLN("loop()");

  FREE_MEMORY();

  // data sampling
#ifdef OLED_ENABLED
  displaySampling();
#endif

  // get sensor data from sensor
  float sensorData[SENSOR_DATA_LEN];
#ifdef AIRQ_SENSOR_ENABLED
  sensorData[AIRQ_DATA_INDEX] = getAQIFromAirQualitySensor();
#endif
#ifdef DHT_SENSOR_ENABLED
  sensorData[DUST_DATA_INDEX] = getDustFromDustSensor();
#endif
#ifdef MQ2_SENSOR_ENABLED
  sensorData[CH4_DATA_INDEX] = getCH4FromMQ2Sensor();
#endif
#ifdef HCHO_SENSOR_ENABLED
  sensorData[HCHO_DATA_INDEX] = getHCHOFromHCHOSensor();
#endif
#ifdef DHT_SENSOR_ENABLED
  sensorData[TEMPERATURE_DATA_INDEX] = getTemperatureFromDHTSensor();
  sensorData[HUMIDITY_DATA_INDEX] = getHumidityFromDHTSensor();
#endif

  // display sensor data in oled
#ifdef OLED_ENABLED
  displaySensorData(sensorData);
  displaySampling();
#endif

  // send sensor data to yeelink server
#ifdef NETWORK_ENABLED
  sendSensorDataToYeelink(sensorData[AIRQ_DATA_INDEX], SENSOR_AIRQ_DATA_INDEX);
  sendSensorDataToYeelink(sensorData[HCHO_DATA_INDEX], SENSOR_HCHO_DATA_INDEX);
  sendSensorDataToYeelink(sensorData[DUST_DATA_INDEX], SENSOR_DUST_DATA_INDEX);
  sendSensorDataToYeelink(sensorData[CH4_DATA_INDEX], SENSOR_CH4_DATA_INDEX);
  sendSensorDataToYeelink(sensorData[TEMPERATURE_DATA_INDEX], SENSOR_TEMPERATURE_DATA_INDEX);
  sendSensorDataToYeelink(sensorData[HUMIDITY_DATA_INDEX], SENSOR_HUMIDITY_DATA_INDEX);
#endif

#ifdef ALARM_ENABLED
  playAlarm(AIRQ_DATA_INDEX, sensorData[AIRQ_DATA_INDEX]);
#endif

  delay(10000);

}
