#include <SmartTemperature.h>
#ifndef ARDUINO
#include "dtostrf.h"
#endif

void SmartTemperature::update() {
  double currentTemperature = pTemperatureSensor->readTemperature();

  char currentTemperatureStr[6];
  dtostrf(currentTemperature, 1, 1, currentTemperatureStr);
  char message[20];
  snprintf(message, sizeof(message), "%s degrees", currentTemperatureStr);

  pLogger->writeLog(message);
  pLcdScreen->display(message);
}
