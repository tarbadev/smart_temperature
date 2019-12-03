#ifndef SMART_TEMPERATURE_TEMPERATURESENSORMOCK_H
#define SMART_TEMPERATURE_TEMPERATURESENSORMOCK_H

#include "gmock/gmock.h"
#include "TemperatureSensor.h"

class TemperatureSensorMock : public TemperatureSensor {
public:
  TemperatureSensorMock() : TemperatureSensor(210) {}

  MOCK_METHOD(double, readTemperature, ());
};

double TemperatureSensor::readTemperature() { return 0.0; }

#endif //SMART_TEMPERATURE_TEMPERATURESENSORMOCK_H
