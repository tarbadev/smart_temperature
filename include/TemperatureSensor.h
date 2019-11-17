#ifndef ARDUINO_TDD_CPP_TEMPERATURESENSOR_H
#define ARDUINO_TDD_CPP_TEMPERATURESENSOR_H

#include "Arduino.h"

class TemperatureSensor {
public:
  virtual double readTemperature();
  explicit TemperatureSensor(uint8_t pin) {
    this->pin = pin;
  }

private:
  uint8_t pin;
};

#endif //ARDUINO_TDD_CPP_TEMPERATURESENSOR_H
