#ifndef SMART_TEMPERATURE_LOGGERMOCK_H
#define SMART_TEMPERATURE_LOGGERMOCK_H

#include "gmock/gmock.h"
#include "../../../driver/include/Logger.h"

class LoggerMock: public Logger {
public:
  MOCK_METHOD(void, initialize, (uint32_t pin));
  MOCK_METHOD(void, writeLog, (const char *logMessage));
};

#endif //SMART_TEMPERATURE_LOGGERMOCK_H
