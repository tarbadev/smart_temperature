#include "Arduino.h"
#include "LiquidCrystal.h"
#include "gtest/gtest.h"

TEST(ApplicationTest, setup_initializesLogger) {
  uint8_t backLightPin = 13;
  ArduinoMock *pArduinoMock = arduinoMockInstance();
  LiquidCrystalMock *pLiquidCrystalMock = liquidCrystalMockInstance();
  SerialMock *pSerialMock = serialMockInstance();

  EXPECT_CALL(*pSerialMock, begin(testing::Eq(9600))).Times(testing::Exactly(1));
  EXPECT_CALL(*pArduinoMock, pinMode(testing::Eq(backLightPin), testing::Eq(OUTPUT)));
  EXPECT_CALL(*pLiquidCrystalMock, begin(testing::Eq(16), testing::Eq(2), testing::Eq(LCD_5x8DOTS))).Times(testing::Exactly(1));
  EXPECT_CALL(*pLiquidCrystalMock, clear());
  EXPECT_CALL(*pArduinoMock, analogWrite(testing::Eq(backLightPin), testing::Eq(HIGH)));

  setup();

  releaseSerialMock();
  releaseLiquidCrystalMock();
  releaseArduinoMock();
}

TEST(ApplicationTest, loop_readsTemperatureAndWaits1Seconds) {
  ArduinoMock *pArduinoMock = arduinoMockInstance();
  SerialMock *pSerialMock = serialMockInstance();
  LiquidCrystalMock *pLiquidCrystalMock = liquidCrystalMockInstance();

  EXPECT_CALL(*pArduinoMock, analogRead(testing::Eq(A0))).WillOnce(testing::Return(124));
  EXPECT_CALL(*pSerialMock, println(testing::SafeMatcherCast<const char *>(testing::StrEq("10.5C. degrees"))));
  EXPECT_CALL(*pLiquidCrystalMock, clear());
  EXPECT_CALL(*pLiquidCrystalMock, print(testing::SafeMatcherCast<const char *>(testing::StrEq("10.5C. degrees"))));
  EXPECT_CALL(*pArduinoMock, delay(testing::Eq(1000)));

  loop();

  releaseArduinoMock();
  releaseSerialMock();
  releaseLiquidCrystalMock();
}