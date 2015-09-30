#include"AirQuality.h"
#include"Arduino.h"
AirQuality airqualitysensor;
int current_quality = -1;

void initAirQualitySensor() {
  Serial.println("initAirQualitySensor()");
  Serial.begin(9600);
  airqualitysensor.init(14);
}

int getSensorValueFromAirQualitySensor() {
  Serial.println("getSensorValueFromAirQualitySensor()");
  current_quality = airqualitysensor.slope();
  Serial.println("current_quality=" + (String)current_quality);
  delay(5000);
  return current_quality;
}

ISR(TIMER2_OVF_vect)
{
  if (airqualitysensor.counter == 122) //set 2 seconds as a detected duty
  {
    airqualitysensor.last_vol = airqualitysensor.first_vol;
    airqualitysensor.first_vol = analogRead(A0);
    airqualitysensor.counter = 0;
    airqualitysensor.timer_index = 1;
    PORTB = PORTB ^ 0x20;
  }
  else
  {
    airqualitysensor.counter++;
  }
}


