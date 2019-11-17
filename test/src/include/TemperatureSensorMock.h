#ifndef ARDUINO_TDD_CPP_TEMPERATURESENSORMOCK_H
#define ARDUINO_TDD_CPP_TEMPERATURESENSORMOCK_H

#include "gmock/gmock.h"
#include <TemperatureSensor.h>

class TemperatureSensorMock: public TemperatureSensor {
public:
  TemperatureSensorMock() : TemperatureSensor(210){}
  MOCK_METHOD(float, readTemperature, ());
};

#endif //ARDUINO_TDD_CPP_TEMPERATURESENSORMOCK_H
