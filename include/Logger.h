#ifndef SMART_TEMPERATURE_LOGGER_H
#define SMART_TEMPERATURE_LOGGER_H

#include "Arduino.h"

class Logger {
public:
  virtual void initialize(uint32_t pin);
  virtual void writeLog(const char *pLogMessage);
};

#endif //SMART_TEMPERATURE_LOGGER_H
