#include <SmartTemperature.h>
#include <TemperatureSensorMock.h>
#include <LoggerMock.h>
#include <LcdScreenMock.h>
#include "gtest/gtest.h"

using ::testing::StrEq;
using ::testing::Exactly;
using ::testing::Return;

class SmartTemperatureTest : public ::testing::Test {
public:
protected:
  void SetUp() override {
    smartTemperature = new SmartTemperature(&loggerMock, &temperatureSensorMock, &lcdScreenMock);
  }

  void TearDown() override {
    delete smartTemperature;
  }

  LoggerMock loggerMock;
  LcdScreenMock lcdScreenMock;
  TemperatureSensorMock temperatureSensorMock;
  SmartTemperature *smartTemperature{};
};

TEST_F(SmartTemperatureTest, update_readsTemperature_andLogsIt) {
  EXPECT_CALL(temperatureSensorMock, readTemperature)
      .Times(Exactly(1))
      .WillOnce(Return(15.312));
  EXPECT_CALL(loggerMock, writeLog(StrEq("15.3C. degrees"))).Times(Exactly(1));
  EXPECT_CALL(lcdScreenMock, display(StrEq("15.3C. degrees"))).Times(Exactly(1));

  smartTemperature->update();
}