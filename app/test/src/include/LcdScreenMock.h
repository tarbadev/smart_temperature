#ifndef SMART_TEMPERATURE_LCDSCREENMOCK_H
#define SMART_TEMPERATURE_LCDSCREENMOCK_H

#include "../../../driver/include/LcdScreen.h"

class LcdScreenMock : public LcdScreen {
public:
  LcdScreenMock() : LcdScreen(nullptr) {}

  MOCK_METHOD(void, display, (const char *message));
};

#endif //SMART_TEMPERATURE_LCDSCREENMOCK_H
