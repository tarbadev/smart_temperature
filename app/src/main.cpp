#include <Arduino.h>
#include <LiquidCrystal.h>
#include <SmartTemperature.h>
#include <Logger.h>
#include <LcdScreen.h>
#include <TemperatureSensor.h>

TemperatureSensor temperatureSensor(A0);
Logger logger;
LiquidCrystal liquidCrystal(12, 11, 5, 4, 3, 2);
LcdScreen lcdScreen(&liquidCrystal);
SmartTemperature smartTemperature(&logger, &temperatureSensor, &lcdScreen);

void setup() {
  logger.initialize(9600);
  lcdScreen.initialize();
}

void loop() {
  smartTemperature.update();
  delay(10000);
}
