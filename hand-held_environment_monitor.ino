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

void testAirQuality()
{
  LOG_PRINTLN("---------------testAirQuality()---------------");
#ifdef AIRQ_SENSOR_ENABLED
  int airQuality = getAQIFromAirQualitySensor();
#ifdef OLED_ENABLED
  displayAirQ(airQuality);
#endif
#ifdef BUZZER_ENABLED
  playAlarm(AIRQ_DATA_INDEX, airQuality);
#endif
#ifdef NETWORK_ENABLED
  sendSensorDataToYeelink(airQuality, SENSOR_AIRQ_DATA_INDEX);
#endif
#endif
}

void testDust()
{
  LOG_PRINTLN("---------------testDust()---------------");
#ifdef DUST_SENSOR_ENABLED
  float dust = getDustFromDustSensor();
#ifdef OLED_ENABLED
  displayDust(dust);
#endif
#ifdef BUZZER_ENABLED
  playAlarm(DUST_DATA_INDEX, dust);
#endif
#ifdef NETWORK_ENABLED
  sendSensorDataToYeelink(dust, SENSOR_DUST_DATA_INDEX);
#endif
#endif
}

void testMQ2()
{
  LOG_PRINTLN("---------------testMQ2()---------------");
#ifdef MQ2_SENSOR_ENABLED
  float ch4 = getCH4FromMQ2Sensor();
#ifdef OLED_ENABLED
  displayCH4(ch4);
#endif
#ifdef BUZZER_ENABLED
  playAlarm(CH4_DATA_INDEX, ch4);
#endif
#ifdef NETWORK_ENABLED
  sendSensorDataToYeelink(ch4, SENSOR_CH4_DATA_INDEX);
#endif
#endif
}

void testDHT()
{
  LOG_PRINTLN("---------------testDHT()---------------");
#ifdef DHT_SENSOR_ENABLED
  float temp = getTemperatureFromDHTSensor();
#ifdef OLED_ENABLED
  displayTemp(temp);
#endif
#ifdef BUZZER_ENABLED
  playAlarm(TEMPERATURE_DATA_INDEX, temp);
#endif
#ifdef NETWORK_ENABLED
  sendSensorDataToYeelink(temp, SENSOR_TEMPERATURE_DATA_INDEX);
#endif
  float humidity = getHumidityFromDHTSensor();
#ifdef OLED_ENABLED
  displayHumidity(humidity);
#endif
#ifdef BUZZER_ENABLED
  playAlarm(HUMIDITY_DATA_INDEX, humidity);
#endif
#ifdef NETWORK_ENABLED
  sendSensorDataToYeelink(humidity, SENSOR_HUMIDITY_DATA_INDEX);
#endif
#endif
}

void testHCHO()
{
  LOG_PRINTLN("---------------testHCHO()---------------");
#ifdef HCHO_SENSOR_ENABLED
  float hcho = getHCHOFromHCHOSensor();
#ifdef OLED_ENABLED
  displayHCHO(hcho);
#endif
#ifdef BUZZER_ENABLED
  playAlarm(HCHO_DATA_INDEX, hcho);
#endif
#ifdef NETWORK_ENABLED
  sendSensorDataToYeelink(hcho, SENSOR_HCHO_DATA_INDEX);
#endif
#endif
}

void loop() {
  LOG_PRINTLN("loop()");
  FREE_MEMORY();
  
  testAirQuality();
  testDHT();
  testDust();
  testMQ2();
  testHCHO();

#ifdef OLED_ENABLED
  displaySampling();
#endif

  delay(LOOP_TIME);

}
