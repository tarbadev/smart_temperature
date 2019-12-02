#ifndef SMART_TEMPERATURE_LCDSCREEN_H
#define SMART_TEMPERATURE_LCDSCREEN_H

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

#endif //SMART_TEMPERATURE_LCDSCREEN_H
