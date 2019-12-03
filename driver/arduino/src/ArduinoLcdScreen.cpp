#include "LcdScreen.h"

void LcdScreen::initialize() {
  pLiquidCrystal->begin(16, 2);
}

void LcdScreen::display(const char *message) {
  pLiquidCrystal->clear();
  pLiquidCrystal->print(message);
}