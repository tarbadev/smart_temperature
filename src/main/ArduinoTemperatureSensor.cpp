#include <TemperatureSensor.h>

double TemperatureSensor::readTemperature() {
  int total = 0;
  int samples = 64;

  for (int i = 0; i < samples; ++i) {
    total += analogRead(pin);
  }

  double sensorVal = (double)total / samples;
  double voltage = (sensorVal / 1024) * 5.0;
  return (voltage - 0.5) * 100;
}