#include <Logger.h>
#include <Serial.h>
#include "gtest/gtest.h"

using ::testing::SafeMatcherCast;
using ::testing::Exactly;

TEST(LoggerTest, writeLog_CallsSerial) {
  const char *message = "test";
  SerialMock *pSerialMock = serialMockInstance();
  Logger logger;

  EXPECT_CALL(*pSerialMock, println(SafeMatcherCast<const char*>(message))).Times(Exactly(1));

  logger.writeLog(message);

  releaseSerialMock();
}