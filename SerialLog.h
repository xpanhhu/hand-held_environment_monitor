#ifndef SERIAL_LOG_H
#define SERIAL_LOG_H

#define DEBUG
#ifdef DEBUG
#define LOG_PRINT(str)\
  Serial.print(str)
#define LOG_PRINTLN(str)\
  Serial.println(str)
#else
#define LOG_PRINT(str)
#define LOG_PRINTLN(str)
#endif

#endif
