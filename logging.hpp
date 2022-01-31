#pragma once

#include <iostream>
#include <map>
#include <stdlib.h>
#include <string>

using std::string;
using std::ostream;

namespace logger {

enum messageTypes { INFORMATIVE, EDGECASE, MINOR_ERROR, FATAL_ERROR };
class Logger {
public:
 
  void logTo(int type, string message, int linenum, string file, ostream& ostrm); 
  void log(int type, string message, int linenum, string file);
  void setVerbosity(int v); 

private:
  int verbosity = 2;
};
} // namespace logger
