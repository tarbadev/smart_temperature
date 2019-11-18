#ifndef ARDUINO_TDD_CPP_LCDSCREENMOCK_H
#define ARDUINO_TDD_CPP_LCDSCREENMOCK_H

#include <LcdScreen.h>

class LcdScreenMock : public LcdScreen {
public:
  LcdScreenMock() : LcdScreen(nullptr) {}

  MOCK_METHOD(void, display, (const char *message));
};

#endif //ARDUINO_TDD_CPP_LCDSCREENMOCK_H
