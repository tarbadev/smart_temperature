#ifndef SMART_TEMPERATURE_TEMPERATURESENSOR_H
#define SMART_TEMPERATURE_TEMPERATURESENSOR_H

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

#endif //SMART_TEMPERATURE_TEMPERATURESENSOR_H
