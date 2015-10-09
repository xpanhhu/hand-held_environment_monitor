// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include "DHT.h"

#define DHTPIN 2     // what pin we're connected to

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTPIN, DHTTYPE);

void initDHTSensor() {
  Serial.println("initTemperatureAndHumiditySensor()");
  Serial.begin(9600);
  dht.begin();
}

// Reading temperature or humidity takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
float getTemperatureFromDHTSensor()
{
  pinMode(DHT_SENSOR_DIGITAL_PIN, INPUT);
  Serial.println("getTemperatureFromDHTSensor()");
  float t = dht.readTemperature();
  if (isnan(t))
  {
    Serial.println("Failed to read from DHT");
  }
  else
  {
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println(" *C");
  }
  pinMode(DHT_SENSOR_DIGITAL_PIN, OUTPUT);
  return t;
}

float getHumidityFromDHTSensor()
{
  pinMode(DHT_SENSOR_DIGITAL_PIN, INPUT);
  Serial.println("getHumidityFromDHTSensor()");
  float h = dht.readHumidity();
  if (isnan(h))
  {
    Serial.println("Failed to read from DHT");
  }
  else
  {
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.println(" %");
  }
  pinMode(DHT_SENSOR_DIGITAL_PIN, OUTPUT);
  return h;
}
