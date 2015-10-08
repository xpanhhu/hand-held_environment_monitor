/* Grove - HCHO Sensor Demo v1.0
 Interface to Winsen WSP2110 Sensor
 Written September 2015

 http://www.seeedstudio.com/wiki/Grove-HCHO_Sensor
 http://www.seeedstudio.com/wiki/images/c/c3/WSP2110.pdf

 JST Pin 1 (Black Wire)  => Arduino GND
 JST Pin 2 (Red wire)    => Arduino 5VDC
 JST Pin 4 (Yellow wire) => Arduino Analog Pin 0
 */
float Vstart = 0.1588;
float Vc = 4.95;
float Rl = 4.53;
int temperature = 25;
float c2h6o = 46.0700;
float hcho = 30.0300;

void initHchoSensor() {
  Serial.println("initHchoSensor()");
  Serial.begin(9600);
}

float hcho_sensor_execute(int pin) {
  Serial.println("hcho_sensor_execute()");

  //1, read the sensor and covert sensor value
  int sensorValue = analogRead(A1);
  float Vrl = sensorValue * 4.95 / 1023;

  //2, calculate ppm, this formula is from http://www.instructables.com/id/Simple-Arduino-Formaldehyde-Sensor/
  float ppm = 212.32619543773774 * exp(-(7.653015806367451 * (4.95 - Vrl) * Vstart) / (Vrl * (4.95 - Vstart)));
  Serial.print("HCHO in ppm: ");
  Serial.print(ppm);
  Serial.println("ppm");

  //3, calculate mg/m3
  float mg = hcho * ppm / 22.40 * 273 / (273 + temperature);
  Serial.print("HCHO in mg: ");
  Serial.print(mg);
  Serial.println("mg/m3");

  //4, delay and return
  return mg;
}
