#include"AirQuality.h"
#include"Arduino.h"
AirQuality airqualitysensor;

void initAirQualitySensor()
{
#ifdef AIRQ_SENSOR_ENABLED
  LOG_PRINTLN("initAirQualitySensor()");
  airqualitysensor.init(14);
#endif
}
int getAQIFromAirQualitySensor()
{
#ifdef AIRQ_SENSOR_ENABLED
  LOG_PRINTLN("getAQIFromAirQualitySensor()");
  return airqualitysensor.slope();
#endif
}

#ifdef AIRQ_SENSOR_ENABLED
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
#endif
