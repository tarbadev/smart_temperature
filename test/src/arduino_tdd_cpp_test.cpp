#include "Arduino.h"
#include "gtest/gtest.h"
#include "../src/arduino_tdd_cpp.ino"

TEST(ApplicationTest, setup_initializesLogger) {
  SerialMock *pSerialMock = serialMockInstance();

  EXPECT_CALL(*pSerialMock, begin(testing::Eq(9600))).Times(testing::Exactly(1));

  setup();

  releaseSerialMock();
}

TEST(ApplicationTest, loop_readsTemperatureAndWaits10Seconds) {
  ArduinoMock *pArduinoMock = arduinoMockInstance();
  SerialMock *pSerialMock = serialMockInstance();

  EXPECT_CALL(*pArduinoMock, analogRead(testing::Eq(A0)))
      .WillRepeatedly(testing::Return(124));
  EXPECT_CALL(*pSerialMock, println(testing::SafeMatcherCast<const char *>(testing::StrEq("10.5 degrees"))));
  EXPECT_CALL(*pArduinoMock, delay(testing::Eq(10000)));

  loop();

  releaseArduinoMock();
  releaseSerialMock();
}