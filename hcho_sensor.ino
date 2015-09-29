/* Grove - HCHO Sensor Demo v1.0
 Interface to Winsen WSP2110 Sensor
 Written September 2015

 http://www.seeedstudio.com/wiki/Grove-HCHO_Sensor
 http://www.seeedstudio.com/wiki/images/c/c3/WSP2110.pdf

 JST Pin 1 (Black Wire)  => Arduino GND
 JST Pin 2 (Red wire)    => Arduino 5VDC
 JST Pin 4 (Yellow wire) => Arduino Analog Pin 0
 */

void hcho_sensor_execute() {
  float Vi = 0.1;
  float Vc = 4.95; //Constant voltage from pin
  int sensorValue = analogRead(A0); //Read analog pin for voltage info in 10bits
  float Vf = sensorValue * 4.95 / 1023; // Voltage through pin when in presence of VOCs(formaldehyde)
  //Serial.print("Vf: ");
  //Serial.println(Vf);
  Serial.print("HCHo Concentration: ");
  Serial.print(concentrationPPMform(Vf, Vi));
  Serial.print("ppm\n"); //Print concentration data
  delay(2000);
}

float concentrationPPMform(float V, float Vstart) { //formaldehde concentration
  float con = 212.32619543773774 * exp(-(7.653015806367451 * (4.95 - V) * Vstart / (V * (4.95 - Vstart))));
  return con;
}
