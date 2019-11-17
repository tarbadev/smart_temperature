#include <Arduino.h>
#include "User_Setup.h"
#include "TemperatureSensor.h"

TemperatureSensor temperatureSensor;

void setup() {
}

void loop() {
  temperatureSensor.setCurrentTemperature(15);
}
