float threshold[] = { 1, 1, 1, 1, 1, 1};

void initBuzzer()
{
  LOG_PRINTLN("initBuzzer()");
  pinMode(BUZZER_DIGITAL_PIN, OUTPUT);
}

void playAlarm(int sensorIndex, float sensorValue)
{
  LOG_PRINTLN("playAlarm()");
  float yeeLinkValue = getSensorDataFromYeelink("", "378115");
  if (yeeLinkValue < 1)return;
  if (sensorValue >= threshold[sensorIndex]) {
    digitalWrite(BUZZER_DIGITAL_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_DIGITAL_PIN, LOW);
  }

}
