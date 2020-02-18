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
      .WillOnce(Return(124));

  double temperature = temperatureSensor.readTemperature();
  EXPECT_DOUBLE_EQ(temperature, 10.546875);

  releaseArduinoMock();
}