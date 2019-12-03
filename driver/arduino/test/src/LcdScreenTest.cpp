#include <LcdScreen.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <LiquidCrystal.h>

TEST(LcdScreenTest, initialize_CallsLcdBegin) {
  LiquidCrystalMock *pLiquidCrystalMock = liquidCrystalMockInstance();
  LiquidCrystal liquidCrystal(0, 1, 2, 3, 4, 5);

  EXPECT_CALL(*pLiquidCrystalMock, begin(testing::Eq(16), testing::Eq(2), testing::Eq(LCD_5x8DOTS))).Times(testing::Exactly(1));

  LcdScreen lcdScreen(&liquidCrystal);
  lcdScreen.initialize();

  releaseLiquidCrystalMock();
}

TEST(LcdScreenTest, display_CallsLcdPrint) {
  const char* message = "Some message to display";
  LiquidCrystal liquidCrystal(0, 1, 2, 3, 4, 5);
  LiquidCrystalMock *pLiquidCrystalMock = liquidCrystalMockInstance();

  EXPECT_CALL(*pLiquidCrystalMock, clear()).Times(testing::Exactly(1));
  EXPECT_CALL(*pLiquidCrystalMock, print(testing::SafeMatcherCast<const char*>(message))).Times(testing::Exactly(1));

  LcdScreen lcdScreen(&liquidCrystal);
  lcdScreen.display(message);

  releaseLiquidCrystalMock();
}