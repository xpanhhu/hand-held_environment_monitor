float dust_sensor_execute(int pin) {
  unsigned long duration;
  unsigned long starttime;
  unsigned long ratio = 0;
  unsigned long sampletime_ms = 30000;//sampe 30s ;
  unsigned long lowpulseoccupancy = 0;
  unsigned long concentration = 0;
  
  pinMode(pin, INPUT);
  delay(500);
  
  starttime = millis();//get the current time;
  while (true) {
    duration = pulseIn(pin, LOW);
    if ((millis() - starttime) >= sampletime_ms) //if the sampel time == 30s
    {
      ratio = lowpulseoccupancy / (sampletime_ms * 10.0); // Integer percentage 0=>100
      concentration = 1.1 * pow(ratio, 3) - 3.8 * pow(ratio, 2) + 520 * ratio + 0.62; // using spec sheet curve
      lowpulseoccupancy = 0;
      break;
    } else {
      lowpulseoccupancy = lowpulseoccupancy + duration;
    }
  }
  
  pinMode(pin, OUTPUT);
  
  return concentration;
}
