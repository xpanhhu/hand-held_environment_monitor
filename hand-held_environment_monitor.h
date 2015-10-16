#ifndef HAND_HELD_ENV_MONITOR_H
#define HAND_HELD_ENV_MONITOR_H

// Comment out the code if need to disable a component
#define OLED_ENABLED
#define NETWORK_ENABLED
#define BUZZER_ENABLED
#define DUST_SENSOR_ENABLED
#define HCHO_SENSOR_ENABLED
#define MQ2_SENSOR_ENABLED
#define DHT_SENSOR_ENABLED
//#define AIRQ_SENSOR_ENABLED // this sensor with oled may have resource conflict, need to enhanced.

// Comment out the SERIAL_ENABLE if need to close debug log
//#define SERIAL_ENABLE

#ifdef SERIAL_ENABLE
#define LOG_PRINT(str)\
  Serial.print(str)
#define LOG_PRINTLN(str)\
  Serial.println(str)
#else
#define LOG_PRINT(str)
#define LOG_PRINTLN(str)
#endif

#define MQ2_SENSOR_ANALOG_PIN A0
#define HCHO_SENSOR_ANALOG_PIN A1
#define AIRQ_SENSOR_ANALOG_PIN A2

#define DHT_SENSOR_DIGITAL_PIN 2
#define DUST_SENSOR_DIGITAL_PIN 3
#define BUZZER_DIGITAL_PIN 5

#define DATA_DISPLAY_TIME_DURATION 5000
#define SAMPLING_TIME_DURATION 10000
#define BUZZER_TIME_DURATION 2000

#define DUST_DATA_INDEX 0
#define HCHO_DATA_INDEX 1
#define AIRQ_DATA_INDEX 2
#define MQ2_CH4_DATA_INDEX 3
#define DHT_TEMP_DATA_INDEX 4
#define DHT_HUMIDITY_DATA_INDEX 5

const float ALARM_THRESHOLD_MINS[] = { 0, 0, 0, 0, 15, 30};
const float ALARM_THRESHOLD_MAXS[] = { 2000, 0.08, 1, 2000, 30, 80};

#endif

