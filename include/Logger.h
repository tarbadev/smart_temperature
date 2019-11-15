#ifndef ARDUINO_TDD_CPP_LOGGER_H
#define ARDUINO_TDD_CPP_LOGGER_H

#include <iostream>

class Logger {
public:
  virtual void writeLog(std::string logMessage);
};

#endif //ARDUINO_TDD_CPP_LOGGER_H
