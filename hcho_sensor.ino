//void hcho_sensor_init() {
//  Serial.begin(9600);
//}

void hcho_sensor_execute() {
  int sensorValue = analogRead(A0);
  float Vol = sensorValue * 4.95 / 1023;
  Serial.print("Vol = ");
  Serial.println(Vol);
  delay(500);
}
