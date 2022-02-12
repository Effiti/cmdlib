#pragma once

#include <iostream>
#include <map>
#include <stdlib.h>
#include <string>

using std::ostream;
using std::string;

namespace logger {

enum class messageType { DEBUG, INFORMATIVE, EDGECASE, MINOR_ERROR, FATAL_ERROR };
class Logger {
public:
  Logger(int v) : mVerbosity{v} {};

  void logTo(messageType type, string message,
             ostream &ostrm, int linenum=-1, string file="");
  void log(messageType type, string message, int linenum=-1, string file="");
  void setVerbosity(int v);

private:
  int mVerbosity = 2;
  std::string mTellPos(int linenum, string file);
};
} // namespace logger
