#include <LcdScreen.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <LiquidCrystal.h>
#include <Arduino.h>

using ::testing::Eq;

TEST(LcdScreenTest, initialize_CallsSetsTheContrastAndInitializesLcdScreen) {
  LiquidCrystalMock *pLiquidCrystalMock = liquidCrystalMockInstance();
  ArduinoMock *pArduinoMock = arduinoMockInstance();
  LiquidCrystal liquidCrystal(0, 1, 2, 3, 4, 5);
  uint8_t backLightPin = 12;

  EXPECT_CALL(*pLiquidCrystalMock, begin(Eq(16), Eq(2), Eq(LCD_5x8DOTS)));
  EXPECT_CALL(*pArduinoMock, pinMode(Eq(backLightPin), Eq(OUTPUT)));
  EXPECT_CALL(*pArduinoMock, analogWrite(Eq(backLightPin), Eq(HIGH)));
  EXPECT_CALL(*pLiquidCrystalMock, print(testing::SafeMatcherCast<const char*>("Initializing...")));

  LcdScreen lcdScreen(&liquidCrystal, backLightPin);
  lcdScreen.initialize();

  releaseLiquidCrystalMock();
  releaseArduinoMock();
}

TEST(LcdScreenTest, display_CallsLcdPrint) {
  const char* message = "Some message to display";
  LiquidCrystal liquidCrystal(0, 1, 2, 3, 4, 5);
  LiquidCrystalMock *pLiquidCrystalMock = liquidCrystalMockInstance();

  EXPECT_CALL(*pLiquidCrystalMock, clear()).Times(testing::Exactly(1));
  EXPECT_CALL(*pLiquidCrystalMock, print(testing::SafeMatcherCast<const char*>(message))).Times(testing::Exactly(1));

  LcdScreen lcdScreen(&liquidCrystal, 0);
  lcdScreen.display(message);

  releaseLiquidCrystalMock();
}