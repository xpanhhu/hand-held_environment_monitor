float R0;
void mq2_sensor_init() {
  float sensor_volt;
  float RS_air; //  Get the value of RS via in a clear air
  float sensorValue;

  /*--- Get a average data by testing 100 times ---*/
  for (int x = 0 ; x < 100 ; x++)
  {
    sensorValue = sensorValue + analogRead(A0);
  }
  sensorValue = sensorValue / 100.0;
  /*-----------------------------------------------*/

  sensor_volt = sensorValue / 1024 * 5.0;
  RS_air = (5.0 - sensor_volt) / sensor_volt; // omit *RL
  R0 = RS_air; // The ratio of RS/R0 is 10 in a clear air

  Serial.print("sensor_volt = ");
  Serial.print(sensor_volt);
  Serial.println("V");

  Serial.print("R0 = ");
  Serial.println(R0);
  
}

void mq2_sensor_execute() {
  Serial.print("R0 = ");
  Serial.println(R0);
  float sensor_volt;
  float RS_gas; // Get value of RS in a GAS
  float ratio; // Get ratio RS_GAS/RS_air
  float sensorValue = analogRead(A0);
  sensor_volt = (float)sensorValue / 1024 * 5.0;
  RS_gas = (5.0 - sensor_volt) / sensor_volt; // omit *RL

  /*-Replace the name "R0" with the value of R0 in the demo of First Test -*/
  ratio = RS_gas / R0; // ratio = RS/R0
  /*-----------------------------------------------------------------------*/

  Serial.print("sensor_volt = ");
  Serial.println(sensor_volt);
  Serial.print("RS_ratio = ");
  Serial.println(RS_gas);
  Serial.print("Rs/R0 = ");
  Serial.println(ratio);

  //float H2 = 1000 * ratio ;
  
  float CH4 = 1000 * ratio /1.8;
  float Smoke = 1000 * ratio/1.9;
  Serial.print("CH4 = ");
  Serial.print(CH4);
  Serial.print("SMOKE = ");
  Serial.print(Smoke);
  Serial.print("\n\n");

  delay(1000);

}
