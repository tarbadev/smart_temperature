#include "TemperatureSensor.h"

void TemperatureSensor::setCurrentTemperature(double currentTemperature) {
  const char *pDegrees = "degrees";
  char logMessage [strlen(pDegrees) + 5];
  sprintf(logMessage, "%0.1f degrees", currentTemperature);

  pLogger->writeLog(logMessage);
}
