#pragma once

#include <iostream>
#include <map>
#include <stdlib.h>
#include <string>

using std::ostream;
using std::string;

namespace logger {

enum class messageTypes { DEBUG, INFORMATIVE, EDGECASE, MINOR_ERROR, FATAL_ERROR };
class Logger {
public:
  Logger(int v) : mVerbosity{v} {};

  void logTo(messageTypes type, string message, int linenum, string file,
             ostream &ostrm);
  void log(messageTypes type, string message, int linenum, string file);
  void setVerbosity(int v);

private:
  int mVerbosity = 2;
};
} // namespace logger
