#include <Arduino.h>
#include "LcdScreen.h"

void LcdScreen::initialize() {
  pinMode(backLightPin, OUTPUT);
  analogWrite(backLightPin, HIGH);
  pLiquidCrystal->begin(16, 2);
  pLiquidCrystal->print("Initializing...");
}

void LcdScreen::display(const char *message) {
  pLiquidCrystal->clear();
  pLiquidCrystal->print(message);
}