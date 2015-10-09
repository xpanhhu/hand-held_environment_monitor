#include"SeeedOLED.h"
#include <Wire.h>
#include <avr/pgmspace.h>

const unsigned char TietoLogo[] PROGMEM = {
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xEF, 0xCF, 0x8F, 0x0F, 0x0F, 0x0F, 0x8F, 0x8F, 0x0F, 0x0F, 0x0F, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xE1, 0xC0, 0x80, 0x00, 0x00, 0x01, 0x03, 0x07, 0x8F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xF7, 0xE3, 0xC0, 0x80, 0x00, 0x00, 0x03, 0x07, 0x0F,
  0x1F, 0x1F, 0x3F, 0x3F, 0x3F, 0x3E, 0x3E, 0x3E, 0x3F, 0x1F, 0x0F, 0x0F, 0x07, 0x03, 0x00, 0x00,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x7F, 0xFF, 0xFF,
  0xFB, 0xF1, 0xF0, 0xE1, 0x43, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFE, 0xFC, 0xFE, 0x7E,
  0x3F, 0x1E, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F,
  0x7F, 0x7F, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xF3, 0xC1, 0xE0, 0xF0, 0x78, 0x3C, 0x1E, 0x0F,
  0x07, 0x03, 0x81, 0xF0, 0xF8, 0xFC, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xF7, 0xE7, 0xC7, 0x87, 0x07, 0x87, 0xC7, 0xC7, 0x87, 0x0F, 0x1F, 0x3F, 0x1F, 0x8F, 0x87,
  0xC2, 0xE0, 0xF8, 0xF0, 0xE1, 0xC3, 0x87, 0x0F, 0x1F, 0x3F, 0x3F, 0x3F, 0x3E, 0x3E, 0x3C, 0x3E,
  0x3E, 0x1F, 0x1F, 0x0F, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xF1, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x01,
  0x03, 0x87, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF, 0x7F, 0x3E, 0x1C, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
  0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7E, 0x7F,
  0x3F, 0x1F, 0x0F, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void initOled128Display()
{
  Console.println("initOled128Display()");
  Wire.begin();
  SeeedOled.init();  //initialze SEEED OLED display
  DDRB |= 0x21;
  PORTB |= 0x21;
  SeeedOled.clearDisplay();          //clear the screen and set start position to top left corner
  SeeedOled.setNormalDisplay();      //Set display to normal mode (i.e non-inverse mode)
  SeeedOled.setPageMode();           //Set addressing mode to Page Mode
  SeeedOled.setTextXY(0, 0);         //Set the cursor to Xth Page, Yth Column
  SeeedOled.drawBitmap((unsigned char*)TietoLogo, 1024);    // 1024 = 128 Pixels * 64 Pixels / 8
  delay(2000);
  SeeedOled.clearDisplay();
}

void displaySapmlling()
{
  SeeedOled.setTextXY(4, 0);
  SeeedOled.putString("AIR SAMPLLING...");
}

void displayAnalysisResult(int airQuality, float dust, float hcho, float ch4, float temperature, float humidity)
{
  Console.println("displayAnalysisResult()");
  Console.println("airQuality=" + (String)airQuality);
  Console.println("dust=" + (String)dust);
  Console.println("hcho=" + (String)hcho);
  Console.println("ch4=" + (String)ch4);
  Console.println("temperature=" + (String)temperature);
  Console.println("humidity=" + (String)humidity);

  clearCurrentDisplay(0);

  //page 1
  displayHeader();
  displayTemperature(temperature);
  displayHumidity(humidity);
  displayFooter(1);
  clearCurrentDisplay(4000);

  //page 2
  displayHeader();
  displayAirQuality(airQuality);
  displayDust(dust);
  displayFooter(1);
  clearCurrentDisplay(4000);

  //page 3
  displayHeader();
  displayHcho(hcho);
  displayCh4(ch4);
  displayFooter(2);
  clearCurrentDisplay(4000);
}

void displayTemperature(float temperature)
{
  SeeedOled.setTextXY(1, 0);
  SeeedOled.putString("Temperature(C)");
  SeeedOled.setTextXY(2, 0);
  SeeedOled.putFloat(temperature);
}

void displayHumidity(float humidity)
{
  SeeedOled.setTextXY(4, 0);
  SeeedOled.putString("Humidity(%)");
  SeeedOled.setTextXY(5, 0);
  SeeedOled.putFloat(humidity);
}

void displayAirQuality(int airQuality)
{
  SeeedOled.setTextXY(1, 0);
  SeeedOled.putString("AIR QUALITY");
  SeeedOled.setTextXY(2, 0);
  switch (airQuality) {
    case 0:
      SeeedOled.putString("Hazardous");
      break;
    case 1:
      SeeedOled.putString("Very Unhealthy");
      break;
    case 2:
      SeeedOled.putString("Unhealthy");
      break;
    case 3:
      SeeedOled.putString("Good");
      break;
    default:
      break;
  }
}

void displayDust(float dust)
{
  SeeedOled.setTextXY(4, 0);
  SeeedOled.putString("Dust(pcs/0.01cf)");
  SeeedOled.setTextXY(5, 0);
  SeeedOled.putFloat(dust);
}

void displayCh4(float ch4)
{
  SeeedOled.setTextXY(1, 0);
  SeeedOled.putString("CH4(ppm)");
  SeeedOled.setTextXY(2, 0);
  SeeedOled.putFloat(ch4);
}

void displayHcho(float hcho)
{
  SeeedOled.setTextXY(4, 0);
  SeeedOled.putString("HCHO(mg/m3)");
  SeeedOled.setTextXY(5, 0);
  SeeedOled.putFloat(hcho);
}

void displayHeader() {
  SeeedOled.setTextXY(0, 0);
  SeeedOled.putString("----------------");
}

void displayFooter(int pageSize)
{
  SeeedOled.setTextXY(6, 0);
  SeeedOled.putString("----------------");
  SeeedOled.setTextXY(7, 0);
  SeeedOled.putString("        PAGE ");
  SeeedOled.putNumber(pageSize);
  SeeedOled.putString("/3");
}

void clearCurrentDisplay(long delayMs)
{
  if (delayMs > 0)
  {
    delay(delayMs);
  }
  SeeedOled.clearDisplay();
}

