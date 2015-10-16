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
#include "yeelinkclient.h"
#include "MemoryFree.h"
#include "hand-held_environment_monitor.h"

void setup() {
#ifdef NETWORK_ENABLED
  initCloudClient();
#endif
  initSerial();
  initOledDisplay();
  initAirQualitySensor();
  initMQ2Sensor();
  initDHTSensor();
  initBuzzer();

}

void loop() {
  FREE_MEMORY();
  
  displayAirSampling();
  
  testDHT();
  testDust();
  testMQ2();
  testHCHO();
//  testAirQuality();
}

void initSerial()
{
#ifdef SERIAL_ENABLE
  Serial.begin(9600);
#endif
}

void testAirQuality()
{
  LOG_PRINTLN("---------------testAirQuality()---------------");
  int aqi = getAQIFromAirQualitySensor();
  displayAirQ(aqi);
  playAlarm(aqi, AIRQ_DATA_INDEX);
#ifdef NETWORK_ENABLED
  sendSensorDataToCloud(aqi, AIRQ_SENSOR_ID);
#endif
}

void testDHT()
{
  LOG_PRINTLN("---------------testDHT()---------------");
  float temp = getTemperatureFromDHTSensor();
  displayTemp(temp);
  playAlarm(temp, DHT_TEMP_DATA_INDEX);
#ifdef NETWORK_ENABLED
  sendSensorDataToCloud(temp, DHT_TEMP_SENSOR_ID);
#endif
  float humidity = getHumidityFromDHTSensor();
  displayHumidity(humidity);
  playAlarm(humidity, DHT_HUMIDITY_DATA_INDEX);
#ifdef NETWORK_ENABLED
  sendSensorDataToCloud(humidity, DHT_HUMIDITY_SENSOR_ID);
#endif
}

void testDust()
{
  LOG_PRINTLN("---------------testDust()---------------");
  float dust = getDustFromDustSensor();
  displayDust(dust);
  playAlarm(dust, DUST_DATA_INDEX);
#ifdef NETWORK_ENABLED
  sendSensorDataToCloud(dust, DUST_SENSOR_ID);
#endif
}

void testMQ2()
{
  LOG_PRINTLN("---------------testMQ2()---------------");
  float ch4 = getCH4FromMQ2Sensor();
  displayCH4(ch4);
  playAlarm(ch4, MQ2_CH4_DATA_INDEX);
#ifdef NETWORK_ENABLED
  sendSensorDataToCloud(ch4, MQ2_CH4_SENSOR_ID);
#endif
}

void testHCHO()
{
  LOG_PRINTLN("---------------testHCHO()---------------");
  float hcho = getHCHOFromHCHOSensor();
  displayHCHO(hcho);
  playAlarm(hcho, HCHO_DATA_INDEX);
#ifdef NETWORK_ENABLED
  sendSensorDataToCloud(hcho, HCHO_SENSOR_ID);
#endif
}

