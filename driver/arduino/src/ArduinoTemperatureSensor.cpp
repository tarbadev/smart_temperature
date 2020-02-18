#include "TemperatureSensor.h"

double TemperatureSensor::readTemperature() {
  double sensorVal = analogRead(pin);
  double voltage = (sensorVal / 1024) * 5.0;
  return (voltage - 0.5) * 100;
}