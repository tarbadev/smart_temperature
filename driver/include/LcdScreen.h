#ifndef SMART_TEMPERATURE_LCDSCREEN_H
#define SMART_TEMPERATURE_LCDSCREEN_H

#include <LiquidCrystal.h>

class LcdScreen {
public:
  virtual void display(const char *message);
  virtual void initialize();

  explicit LcdScreen(LiquidCrystal *pLiquidCrystal, uint8_t backLightPin) {
    this->pLiquidCrystal = pLiquidCrystal;
    this->backLightPin = backLightPin;
  }
private:
  LiquidCrystal *pLiquidCrystal;
  uint8_t backLightPin;
};

#endif //SMART_TEMPERATURE_LCDSCREEN_H
