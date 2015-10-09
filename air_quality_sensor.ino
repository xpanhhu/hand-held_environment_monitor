#include"AirQuality.h"
#include"Arduino.h"

AirQuality airqualitysensor;

void initAirQualitySensor() {
  airqualitysensor.init(14);
}

int getSensorValueFromAirQualitySensor() {
  pinMode(AIRQ_SENSOR_ANALOG_PIN, INPUT);
  int current_quality = airqualitysensor.slope();
  pinMode(AIRQ_SENSOR_ANALOG_PIN, OUTPUT);
  return current_quality;
}

ISR(TIMER2_OVF_vect)
{
  if (airqualitysensor.counter == 122) //set 2 seconds as a detected duty
  {
    airqualitysensor.last_vol = airqualitysensor.first_vol;
    airqualitysensor.first_vol = analogRead(AIRQ_SENSOR_ANALOG_PIN);
    airqualitysensor.counter = 0;
    airqualitysensor.timer_index = 1;
    PORTB = PORTB ^ 0x20;
  }
  else
  {
    airqualitysensor.counter++;
  }
}

