#include <sstream>
#include "TemperatureSensor.h"

void TemperatureSensor::setCurrentTemperature(double currentTemperature) {
  std::ostringstream logMessage;
  logMessage << currentTemperature << " degrees";
  pLogger->writeLog(logMessage.str());
}
