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
  Console.println("initDHTSensor()");
  dht.begin();
}

// Reading temperature or humidity takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
float getTemperatureFromDHTSensor()
{
  pinMode(DHT_SENSOR_DIGITAL_PIN, INPUT);
  Console.println("getTemperatureFromDHTSensor()");
  float t = dht.readTemperature();
  if (isnan(t))
  {
    Console.println("Failed to read from DHT");
  }
  else
  {
    Console.print("Temperature: ");
    Console.print(t);
    Console.println(" *C");
  }
  pinMode(DHT_SENSOR_DIGITAL_PIN, OUTPUT);
  return t;
}

float getHumidityFromDHTSensor()
{
  pinMode(DHT_SENSOR_DIGITAL_PIN, INPUT);
  Console.println("getHumidityFromDHTSensor()");
  float h = dht.readHumidity();
  if (isnan(h))
  {
    Console.println("Failed to read from DHT");
  }
  else
  {
    Console.print("Humidity: ");
    Console.print(h);
    Console.println(" %");
  }
  pinMode(DHT_SENSOR_DIGITAL_PIN, OUTPUT);
  return h;
}
