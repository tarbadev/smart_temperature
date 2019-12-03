#include "Arduino.h"
#include "gtest/gtest.h"

TEST(ApplicationTest, setup_initializesLogger) {
  LiquidCrystalMock *pLiquidCrystalMock = liquidCrystalMockInstance();
  SerialMock *pSerialMock = serialMockInstance();

  EXPECT_CALL(*pSerialMock, begin(testing::Eq(9600))).Times(testing::Exactly(1));
  EXPECT_CALL(*pLiquidCrystalMock, begin(testing::Eq(16), testing::Eq(2), testing::Eq(LCD_5x8DOTS))).Times(testing::Exactly(1));

  setup();

  releaseSerialMock();
  releaseLiquidCrystalMock();
}

TEST(ApplicationTest, loop_readsTemperatureAndWaits10Seconds) {
  ArduinoMock *pArduinoMock = arduinoMockInstance();
  SerialMock *pSerialMock = serialMockInstance();
  LiquidCrystalMock *pLiquidCrystalMock = liquidCrystalMockInstance();

  EXPECT_CALL(*pArduinoMock, analogRead(testing::Eq(A0)))
      .WillRepeatedly(testing::Return(124));
  EXPECT_CALL(*pSerialMock, println(testing::SafeMatcherCast<const char *>(testing::StrEq("10.5 degrees"))));
  EXPECT_CALL(*pLiquidCrystalMock, clear());
  EXPECT_CALL(*pLiquidCrystalMock, print(testing::SafeMatcherCast<const char *>(testing::StrEq("10.5 degrees"))));
  EXPECT_CALL(*pArduinoMock, delay(testing::Eq(10000)));

  loop();

  releaseArduinoMock();
  releaseSerialMock();
  releaseLiquidCrystalMock();
}