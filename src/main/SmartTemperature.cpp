#include "SmartTemperature.h"

void SmartTemperature::update() {
  double currentTemperature = pTemperatureSensor->readTemperature();

  char logMessage[20];
  snprintf(logMessage, sizeof(logMessage), "%0.1f degrees", currentTemperature);

  pLogger->writeLog(logMessage);
}
