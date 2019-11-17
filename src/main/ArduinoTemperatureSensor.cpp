#include <TemperatureSensor.h>

float TemperatureSensor::readTemperature() {
  int sensorVal = analogRead(pin);
  float voltage = sensorVal * 5.0 / 1024;
  return (voltage - 0.5) * 100;
}