#ifndef ARDUINO_TDD_CPP_TEMPERATURESENSOR_H
#define ARDUINO_TDD_CPP_TEMPERATURESENSOR_H

#include "Logger.h"

class TemperatureSensor {

public:
  void setCurrentTemperature(double currentTemperature);

  explicit TemperatureSensor(Logger *pLogger) {
    this->pLogger = pLogger;
  };

private:
  Logger* pLogger;
};


#endif //ARDUINO_TDD_CPP_TEMPERATURESENSOR_H
