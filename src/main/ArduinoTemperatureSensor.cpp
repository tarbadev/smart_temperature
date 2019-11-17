#include <TemperatureSensor.h>

double TemperatureSensor::readTemperature() {
  int sensorVal = analogRead(pin);
  double voltage = sensorVal * (5.0 / 1024);
  return (voltage - 0.5) * 100;
}