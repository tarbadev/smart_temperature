#ifndef ARDUINO_TDD_CPP_SMARTTEMPERATURE_H
#define ARDUINO_TDD_CPP_SMARTTEMPERATURE_H

#include "Logger.h"
#include "TemperatureSensor.h"

class SmartTemperature {

public:
  void update();

  explicit SmartTemperature(Logger *pLogger, TemperatureSensor *pTemperatureSensor) {
    this->pLogger = pLogger;
    this->pTemperatureSensor = pTemperatureSensor;
  };

private:
  Logger* pLogger;
  TemperatureSensor* pTemperatureSensor;
};


#endif //ARDUINO_TDD_CPP_SMARTTEMPERATURE_H
