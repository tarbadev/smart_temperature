#include "../include/Logger.h"

void Logger::writeLog(const char *pLogMessage) {
  Serial.println(pLogMessage);
}

void Logger::initialize(uint32_t pin) {
  Serial.begin(pin);
}
