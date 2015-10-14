const float THRESHOLD_MINS[] = { 0, 0, 0, 0, 0, 0};
const float THRESHOLD_MAXS[] = { 0, 0, 0, 0, 0, 0};

void initBuzzer()
{
  LOG_PRINTLN("initBuzzer()");
  pinMode(BUZZER_DIGITAL_PIN, OUTPUT);
}

void playAlarm(int sensorIndex, float sensorValue)
{
  LOG_PRINTLN("playAlarm()");
  String responseText = getSensorDataFromYeelink("", "378115");// "{\"timestamp\":\"2015-10-14T16:52:54\",\"value\":1}";
  if (responseText.indexOf("\"value\":0") > 0)
  {
    LOG_PRINTLN("Alarm is off");
    return;
  }
  if (sensorValue >= THRESHOLD_MAXS[sensorIndex] || sensorValue <= THRESHOLD_MINS[sensorIndex]) {
    LOG_PRINTLN("Trun on buzzer");
    digitalWrite(BUZZER_DIGITAL_PIN, HIGH);
    delay(BUZZER_TIME_DURATION);
    LOG_PRINTLN("Trun off buzzer");
    digitalWrite(BUZZER_DIGITAL_PIN, LOW);
  }
}
