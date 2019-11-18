#ifndef ARDUINO_TDD_CPP_LCDSCREEN_H
#define ARDUINO_TDD_CPP_LCDSCREEN_H

#include <LiquidCrystal.h>

class LcdScreen {
public:
  virtual void display(const char *message);
  virtual void initialize();

  explicit LcdScreen(LiquidCrystal *pLiquidCrystal) {
    this->pLiquidCrystal = pLiquidCrystal;
  }
private:
  LiquidCrystal *pLiquidCrystal;
};

#endif //ARDUINO_TDD_CPP_LCDSCREEN_H
