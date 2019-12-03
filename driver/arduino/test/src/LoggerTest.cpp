#include <Logger.h>
#include <Serial.h>
#include "gtest/gtest.h"

using ::testing::SafeMatcherCast;
using ::testing::Exactly;
using ::testing::Eq;

TEST(LoggerTest, initialize_CallsSerialBegin) {
  int pin = 1234;
  SerialMock *pSerialMock = serialMockInstance();

  EXPECT_CALL(*pSerialMock, begin(Eq(pin))).Times(Exactly(1));

  Logger logger;
  logger.initialize(pin);

  releaseSerialMock();
}

TEST(LoggerTest, writeLog_CallsSerialPrintln) {
  const char *message = "test";
  SerialMock *pSerialMock = serialMockInstance();

  EXPECT_CALL(*pSerialMock, println(SafeMatcherCast<const char*>(message))).Times(Exactly(1));

  Logger logger;
  logger.writeLog(message);

  releaseSerialMock();
}