#ifndef ARDUINO_TDD_CPP_LOGGERMOCK_H
#define ARDUINO_TDD_CPP_LOGGERMOCK_H

#include "gmock/gmock.h"
#include <Logger.h>

class LoggerMock: public Logger {
public:
  MOCK_METHOD(void, writeLog, (std::string logMessage));
};

#endif //ARDUINO_TDD_CPP_LOGGERMOCK_H
