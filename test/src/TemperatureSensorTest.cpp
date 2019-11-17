#include <TemperatureSensor.h>
#include "gtest/gtest.h"
#include "LoggerMock.h"

using ::testing::StrEq;
using ::testing::Exactly;

TEST(TemperatureSensorTest, update_logsTemperature) {
  LoggerMock loggerMock;
  TemperatureSensor temperatureSensor(&loggerMock);

  EXPECT_CALL(loggerMock, writeLog(StrEq("15.3 degrees"))).Times(Exactly(1));

  temperatureSensor.setCurrentTemperature(15.3);
}