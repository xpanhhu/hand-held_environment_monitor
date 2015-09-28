/*
 * This demo is an open source machine for detect air quality.
 * dust sensor
 * HCHO sensor
 * MQ2  sensor
 * air  sensor
*/

void setup() {
  Serial.begin(9600);
  dust_sensor_init();
}

void loop() {
  dust_sensor_execute();
  hcho_sensor_execute();
}


