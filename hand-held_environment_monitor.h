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
#define AIRQ_SENSOR_ENABLED

// Comment out the SERIAL_LOG_ENABLE if need to close debug log
//#define SERIAL_LOG_ENABLE
#ifdef SERIAL_LOG_ENABLE
#define LOG_PRINT(str)\
  Serial.print(str)
#define LOG_PRINTLN(str)\
  Serial.println(str)
#else
#define LOG_PRINT(str)
#define LOG_PRINTLN(str)
#endif

#define MEMORY_CHECK_ENABLE//check free memory
#if (defined MEMORY_CHECK_ENABLE) && (defined CONSOLE_ENABLED)
#define FREE_MEMORY()\
  Console.println(freeMemory())
#else
#define FREE_MEMORY()
#endif

#define MQ2_SENSOR_ANALOG_PIN 'A0'
#define HCHO_SENSOR_ANALOG_PIN 'A1'
#define AIRQ_SENSOR_ANALOG_PIN 'A2'

#define DHT_SENSOR_DIGITAL_PIN 2
#define BUZZER_DIGITAL_PIN 5
#define DUST_SENSOR_DIGITAL_PIN 8

#define DUST_DATA_INDEX 0
#define HCHO_DATA_INDEX 1
#define AIRQ_DATA_INDEX 2
#define CH4_DATA_INDEX 3
#define TEMPERATURE_DATA_INDEX 4
#define HUMIDITY_DATA_INDEX 5

#define SENSOR_DUST_DATA_INDEX "377545"//Dust
#define SENSOR_HCHO_DATA_INDEX "377544"//HCHO
#define SENSOR_AIRQ_DATA_INDEX "377542"//Air quality
#define SENSOR_CH4_DATA_INDEX "377887"//CH4
#define SENSOR_TEMPERATURE_DATA_INDEX "377543"//Temperature
#define SENSOR_HUMIDITY_DATA_INDEX "377933" //Humidity 
#define SENSOR_BUZZER_DATA_INDEX "378115" //BUZZER

#define OLED_DISPLAY_TIME 3000
#define LOOP_TIME 10000

#endif

