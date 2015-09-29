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
  mq2_sensor_init();
  airQuality_sensor_init();
  oled128_display_init();
  network_init();
}

void loop() {
  dust_sensor_execute();
  hcho_sensor_execute();
  mq2_sensor_execute();
  airQuality_sensor_execute();
  oled128_display_execute(1, 2.5, 3.5, 4.5, 5.5);
  network_execute();
}


