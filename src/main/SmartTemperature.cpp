#include "SmartTemperature.h"
#ifndef ARDUINO
#include "dtostrf.h"
#endif

void SmartTemperature::update() {
  double currentTemperature = pTemperatureSensor->readTemperature();

  char currentTemperatureStr[6];
  dtostrf(currentTemperature, 1, 1, currentTemperatureStr);
  char logMessage[20];
  snprintf(logMessage, sizeof(logMessage), "%s degrees", currentTemperatureStr);

  pLogger->writeLog(logMessage);
}
