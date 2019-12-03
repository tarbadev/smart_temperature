#include <TemperatureSensor.h>
#include <Arduino.h>
#include "gtest/gtest.h"

using ::testing::SafeMatcherCast;
using ::testing::Exactly;
using ::testing::Eq;
using ::testing::Return;

TEST(TemperatureSensorTest, readTemperature_callsAnalogReadWithPin_andAveragesSeveralReads) {
  uint8_t pin = 123;
  ArduinoMock *pArduinoMock = arduinoMockInstance();
  TemperatureSensor temperatureSensor(pin);

  EXPECT_CALL(*pArduinoMock, analogRead(Eq(pin)))
      .Times(Exactly(64))
      .WillOnce(Return(100))
      .WillOnce(Return(110))
      .WillOnce(Return(120))
      .WillOnce(Return(130))
      .WillOnce(Return(140))
      .WillOnce(Return(150))
      .WillRepeatedly(Return(124));

  double temperature = temperatureSensor.readTemperature();
  EXPECT_GE(temperature, 10.5);
  EXPECT_LE(temperature, 10.6);

  releaseArduinoMock();
}