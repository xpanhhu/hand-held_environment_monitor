float MQ2_R0;

void initMQ2Sensor() {
  LOG_PRINTLN("initMQ2Sensor()");
  float sensor_volt;
  float RS_air; //  Get the value of RS via in a clear air
  float sensorValue;
  for (int x = 0 ; x < 100 ; x++)
  {
    sensorValue = sensorValue + analogRead(MQ2_SENSOR_ANALOG_PIN);
  }
  sensorValue = sensorValue / 100.0;

  sensor_volt = sensorValue / 1024 * 5.0;
  RS_air = (5.0 - sensor_volt) / sensor_volt; // omit *RL
  MQ2_R0 = RS_air; // The ratio of RS/R0 is 10 in a clear air
}

float getCH4FromMQ2Sensor() {
  LOG_PRINTLN("getCH4FromMQ2Sensor()");
  float sensor_volt;
  float RS_gas; // Get value of RS in a GAS
  float ratio; // Get ratio RS_GAS/RS_air
  float sensorValue = analogRead(MQ2_SENSOR_ANALOG_PIN);
  sensor_volt = (float)sensorValue / 1024 * 5.0;
  RS_gas = (5.0 - sensor_volt) / sensor_volt; // omit *RL

  /*-Replace the name "R0" with the value of R0 in the demo of First Test -*/
  ratio = RS_gas / MQ2_R0; // ratio = RS/R0
  /*-----------------------------------------------------------------------*/
  float CH4_PPM = (1000 - 200) * (ratio - 3) / (1.8 - 3) + 200;

  //return CH4_PPM * 16 / 22.4 * 273 / (273 + 25);
  return CH4_PPM;
}
