#ifndef SMART_TEMPERATURE_TEMPERATURESENSORMOCK_H
#define SMART_TEMPERATURE_TEMPERATURESENSORMOCK_H

#include "gmock/gmock.h"
#include "../../../driver/include/TemperatureSensor.h"

class TemperatureSensorMock: public TemperatureSensor {
public:
  TemperatureSensorMock() : TemperatureSensor(210){}
  MOCK_METHOD(double, readTemperature, ());
};

#endif //SMART_TEMPERATURE_TEMPERATURESENSORMOCK_H
