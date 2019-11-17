#ifndef ARDUINO_TDD_CPP_LOGGERMOCK_H
#define ARDUINO_TDD_CPP_LOGGERMOCK_H

#include "gmock/gmock.h"
#include <Logger.h>

class LoggerMock: public Logger {
public:
  MOCK_METHOD(void, initialize, (uint32_t pin));
  MOCK_METHOD(void, writeLog, (const char *logMessage));
};

#endif //ARDUINO_TDD_CPP_LOGGERMOCK_H
