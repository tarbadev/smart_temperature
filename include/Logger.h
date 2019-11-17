#ifndef ARDUINO_TDD_CPP_LOGGER_H
#define ARDUINO_TDD_CPP_LOGGER_H

#include "Arduino.h"

class Logger {
public:
  virtual void writeLog(const char *pLogMessage);
};

#endif //ARDUINO_TDD_CPP_LOGGER_H
