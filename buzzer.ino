void initBuzzer()
{
#ifdef BUZZER_ENABLED
  LOG_PRINTLN("initBuzzer()");
  pinMode(BUZZER_DIGITAL_PIN, OUTPUT);
#endif
}

void playAlarm(float sensorValue, int sensorIndex)
{
#ifdef BUZZER_ENABLED
  LOG_PRINTLN("playAlarm()");
#ifdef NETWORK_ENABLED
  String responseText = getSensorDataFromYeelink("", "378115");// "{\"timestamp\":\"2015-10-14T16:52:54\",\"value\":1}";
#else
  LOG_PRINTLN("NETWORK is disabled");
  return;
#endif
  if (responseText.indexOf("\"value\":0") > 0)
  {
    LOG_PRINTLN("Alarm is off");
    return;
  }
  if (sensorValue >= ALARM_THRESHOLD_MAXS[sensorIndex] || sensorValue <= ALARM_THRESHOLD_MINS[sensorIndex]) {
    LOG_PRINTLN("Trun on buzzer");
    digitalWrite(BUZZER_DIGITAL_PIN, HIGH);
    delay(BUZZER_TIME_DURATION);
    LOG_PRINTLN("Trun off buzzer");
    digitalWrite(BUZZER_DIGITAL_PIN, LOW);
  }
#endif
}
