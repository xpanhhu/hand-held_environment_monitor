/*
 Interface to Shinyei Model PPD42NS Particle Sensor
 Written September 2015

 http://www.seeedstudio.com/wiki/Grove_-_Dust_Sensor
 http://www.sca-shinyei.com/pdf/PPD42NS.pdf

 JST Pin 1 (Black Wire)  => Arduino GND
 JST Pin 3 (Red wire)    => Arduino 5VDC
 JST Pin 4 (Yellow wire) => Arduino Digital Pin 8
 */

float getDustFromDustSensor() {
  LOG_PRINTLN("getDustFromDustSensor()");
  unsigned long duration;
  unsigned long starttime;
  unsigned long ratio = 0;
  unsigned long sampletime_ms = 30000;//sample 30s
  unsigned long lowpulseoccupancy = 0;
  unsigned long concentration = 0;

  pinMode(DUST_SENSOR_DIGITAL_PIN, INPUT);

  starttime = millis();//get the current time;
  while (true) {
    duration = pulseIn(DUST_SENSOR_DIGITAL_PIN, LOW);
    if ((millis() - starttime) >= sampletime_ms) //if the sampel time == 30s
    {
      ratio = lowpulseoccupancy / (sampletime_ms * 10.0); // Integer percentage 0=>100
      concentration = 1.1 * pow(ratio, 3) - 3.8 * pow(ratio, 2) + 520 * ratio + 0.62; // using spec sheet curve by Christopher Nafis
      lowpulseoccupancy = 0;
      break;
    } else {
      lowpulseoccupancy = lowpulseoccupancy + duration;
    }
  }

  pinMode(DUST_SENSOR_DIGITAL_PIN, OUTPUT);

  return concentration;
}
