#include <TemperatureSensor.h>
#include <Arduino.h>
#include "gtest/gtest.h"

using ::testing::SafeMatcherCast;
using ::testing::Exactly;
using ::testing::Eq;
using ::testing::Return;

TEST(TemperatureSensorTest, readTemperature_callsAnalogReadWithPin) {
  uint8_t pin = 123;
  ArduinoMock *pArduinoMock = arduinoMockInstance();
  TemperatureSensor temperatureSensor(pin);

  EXPECT_CALL(*pArduinoMock, analogRead(Eq(pin)))
      .Times(Exactly(1))
      .WillOnce(Return(124));

  float temperature = temperatureSensor.readTemperature();
  EXPECT_GE(temperature, 10.5);
  EXPECT_LE(temperature, 10.6);

  releaseArduinoMock();
}