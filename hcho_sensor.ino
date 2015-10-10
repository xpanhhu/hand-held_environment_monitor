/* Grove - HCHO Sensor Demo v1.0
 Interface to Winsen WSP2110 Sensor
 Written September 2015

 http://www.seeedstudio.com/wiki/Grove-HCHO_Sensor
 http://www.seeedstudio.com/wiki/images/c/c3/WSP2110.pdf

 JST Pin 1 (Black Wire)  => Arduino GND
 JST Pin 2 (Red wire)    => Arduino 5VDC
 JST Pin 4 (Yellow wire) => Arduino Analog Pin 0
 */
#define V_START 0.1588
#define V_C 4.95
#define RL 4.53
#define TEMPERATURE 25
#define C2H6O 46.0700
#define HCHO 30.0300

float getHCHOFromHCHOSensor() {
  //1, read the sensor and covert sensor value
  int sensorValue = analogRead(HCHO_SENSOR_ANALOG_PIN);
  float VRL = sensorValue * 4.95 / 1023;

  //2, calculate ppm, this formula is from http://www.instructables.com/id/Simple-Arduino-Formaldehyde-Sensor/
  float ppm = 212.32619543773774 * exp(-(7.653015806367451 * (4.95 - VRL) * V_START) / (VRL * (4.95 - V_START)));

  //3, calculate mg/m3
  float mg = HCHO * ppm / 22.40 * 273 / (273 + TEMPERATURE);

  //4, delay and return
  return mg;
}
