/*
 * This demo is an open source machine for detect air quality.
 * dust sensor
 * HCHO sensor
 * MQ2  sensor
 * air  sensor
*/
#define DIGIT_PIN_DUST_SENSOR 8
#define ANALOG_PIN_HQ2_SENSOR 0
#define ANALOG_PIN_HCHO_SENSOR 1
#define ANALOG_PIN_AIRQ_SENSOR 2
#define DUST_VALUE 0
#define HCHO_VALUE 1
#define AIRQ_VALUE 2
#define CO_VALUE 3
#define CH4_VALUE 4

float values[5];

void setup() {
  Serial.begin(9600);
  //dust_sensor_init();
  //mq2_sensor_init();
  //airQuality_sensor_init();
  oled128_display_init();
  //network_init();
}

void loop() {
  values[DUST_VALUE] = dust_sensor_execute(DIGIT_PIN_DUST_SENSOR);
  Serial.print("concentration = ");
  Serial.print(values[DUST_VALUE]);
  Serial.println(" pcs/0.01cf");
  Serial.println("\n");
  //  hcho_sensor_execute();
  //  values[HCHO_VALUE] = 0;
  //  Serial.print("HCHO ppm = ");
  //  Serial.print(values[HCHO_VALUE]);
  //  Serial.println("\n");
  //mq2_sensor_execute();
  //  values[CO_VALUE] = 0;
  //  Serial.print("CO ppm= ");
  //  Serial.print(values[CO_VALUE]);
  //  Serial.println("\n");
  //  values[CH4_VALUE] = 0;
  //  Serial.print("CH4 ppm= ");
  //  Serial.print(values[CH4_VALUE]);
  //  Serial.println("\n");
  //  values[AIRQ_VALUE] = airQuality_sensor_execute();
  //  values[AIRQ_VALUE] = 0;
  //  Serial.print("AIRQ = ");
  //  Serial.print(values[AIRQ_VALUE]);
  //  Serial.println("\n");
  //oled128_display_execute();
  oled128_display_execute(0, 200, 0, 0, 0);//air,dust,hcho,co,ch4
  //network_execute();
}

