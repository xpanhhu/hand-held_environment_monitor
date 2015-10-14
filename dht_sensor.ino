// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include "DHT.h"
#define DHTTYPE DHT22   // DHT 22  (AM2302)

DHT dht(DHT_SENSOR_DIGITAL_PIN, DHTTYPE);

void initDHTSensor() {
#ifdef DHT_SENSOR_ENABLED
  LOG_PRINTLN("initDHTSensor()");
  dht.begin();
#endif
}

// Reading temperature or humidity takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
float getTemperatureFromDHTSensor()
{
#ifdef DHT_SENSOR_ENABLED
  LOG_PRINTLN("getTemperatureFromDHTSensor()");
  float t = dht.readTemperature();
  if (isnan(t))
  {
    t = 0; //set default value
  }
  return t;
#endif
}

float getHumidityFromDHTSensor()
{
#ifdef DHT_SENSOR_ENABLED
  LOG_PRINTLN("getHumidityFromDHTSensor()");
  float h = dht.readHumidity();
  if (isnan(h))
  {
    h = 0; //set default value
  }
  return h;
#endif
}
