/*
    WebTai System Techonlogy
    Infrared thermometer Version 1.0
    Designed by JMLIN LIN
    Date:2/09/2020
    Ver1.0 Release 2/09/2020
    http://
    github://
    Vesion: V1.0
*/
// MCU Arduino pro mini 3.3V 8MHZ ATmega328p
#include <Wire.h>
#include <SparkFunMLX90614.h>
#include "SevenSegmentTM1637.h"

//MLX90614
//A4 SDA
//A5 SCL
IRTherm therm;
const byte LED_PIN = 13;//工作指示燈

//TM1637
const byte PIN_CLK = 8; //CLK
const byte PIN_DIO = 9; //DIO
SevenSegmentTM1637 display(PIN_CLK, PIN_DIO);

void setup()
{
  //TM1637初始化
  Serial.begin(9600);
  display.begin();
  display.setBacklight(100);
  display.print("INIT");
  delay(1000);

  //MLX090614初始化
  therm.begin();
  therm.setUnit(TEMP_C);
  pinMode(LED_PIN, OUTPUT);
  setLED(LOW);
}

void loop()
{
  setLED(HIGH);
  if (therm.read())
  {
      display.clear();
      display.print(String(therm.object(), 2).substring(0,4));
      Serial.print(String(therm.object(), 2));
  }
  setLED(LOW);
  delay(200);
}

void setLED(bool on)
{
  if (on)
    digitalWrite(LED_PIN, LOW);
  else
    digitalWrite(LED_PIN, HIGH);
}
