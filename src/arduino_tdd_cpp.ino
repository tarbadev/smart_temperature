#include <Arduino.h>
#include "User_Setup.h"
#include "SmartTemperature.h"
#include "Logger.h"
#include "TemperatureSensor.h"

TemperatureSensor temperatureSensor(A0);
Logger logger;
SmartTemperature smartTemperature(&logger, &temperatureSensor);

void setup() {
  logger.initialize(9600);
}

void loop() {
  smartTemperature.update();
  delay(10000);
}
