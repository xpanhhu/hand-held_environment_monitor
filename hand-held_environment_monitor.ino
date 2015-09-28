

void setup() {
  Serial.begin(9600);
  dust_sensor_init();
}

void loop() {
  dust_sensor_execute();
  hcho_sensor_execute();
}


