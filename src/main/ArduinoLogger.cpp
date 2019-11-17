#include "Logger.h"

void Logger::writeLog(const char *pLogMessage) {
  Serial.println(pLogMessage);
}