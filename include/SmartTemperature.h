#ifndef ARDUINO_TDD_CPP_SMARTTEMPERATURE_H
#define ARDUINO_TDD_CPP_SMARTTEMPERATURE_H

#include "Logger.h"
#include "TemperatureSensor.h"
#include "LcdScreen.h"

class SmartTemperature {

public:
  void update();

  explicit SmartTemperature(Logger *pLogger, TemperatureSensor *pTemperatureSensor, LcdScreen *pLcdScreen) {
    this->pLogger = pLogger;
    this->pTemperatureSensor = pTemperatureSensor;
    this->pLcdScreen = pLcdScreen;
  };

private:
  Logger* pLogger;
  TemperatureSensor* pTemperatureSensor;
  LcdScreen* pLcdScreen;
};


#endif //ARDUINO_TDD_CPP_SMARTTEMPERATURE_H
