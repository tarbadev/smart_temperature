#include "Arduino.h"
#include "gtest/gtest.h"
#include "../src/arduino_tdd_cpp.ino"

TEST(ApplicationTest, setup_initializesLogger) {
  SerialMock *pSerialMock = serialMockInstance();

  EXPECT_CALL(*pSerialMock, begin(testing::Eq(9600))).Times(testing::Exactly(1));

  setup();

  releaseSerialMock();
}

TEST(ApplicationTest, loop_readsTemperature) {
  ArduinoMock *pArduinoMock = arduinoMockInstance();
  SerialMock *pSerialMock = serialMockInstance();

  EXPECT_CALL(*pArduinoMock, analogRead(testing::Eq(A0)))
      .Times(testing::Exactly(1))
      .WillOnce(testing::Return(124));
  EXPECT_CALL(*pSerialMock, println(testing::SafeMatcherCast<const char *>(testing::StrEq("10.5 degrees"))))
      .Times(testing::Exactly(1));

  loop();

  releaseArduinoMock();
  releaseSerialMock();
}