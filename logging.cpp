#include "logging.hpp"
#include <iostream>
#include <string>
#include "common.hpp"

using std::cerr;
using std::endl;
using std::string;
using namespace logger;

void Logger::logTo(int type, string message, int linenum, string file,
                   ostream &ostrm) {
  switch (type) {
  case INFORMATIVE:
    if (verbosity >= 3) {
      ostrm << "[" << CmdUtil::colors["green"] << "INFO" << CmdUtil::colors["end"]
            << "] on line: " << linenum << ", in file: " << file << ": "
            << message << endl;
    }
    break;
  case EDGECASE:
    if (verbosity >= 2) {
      ostrm << "[" << CmdUtil::colors["yellow"] << "EDGECASE" << CmdUtil::colors["end"]
            << "] on line: " << linenum << ", in file: " << file << ":  "
            << message << endl;
    }
    break;
  case MINOR_ERROR:
    if (verbosity >= 1) {
      ostrm << "[" << CmdUtil::colors["magenta"] << "ERROR" << CmdUtil::colors["end"]
            << "] on line: " << linenum << ", in file: " << file << ": "
            << message << endl;
    }
    break;
  case FATAL_ERROR:
    ostrm << "[" << CmdUtil::colors["red"] << "FATAL" << CmdUtil::colors["end"]
          << "] on line: " << linenum << ", in file: " << file << ": "
          << message << endl;
    exit(EXIT_FAILURE);
    break;
  }
}
void Logger::log(int type, string message, int linenum, string file) {
  this->logTo(type, message, linenum, file, cerr);
}
void Logger::setVerbosity(int v) { this->verbosity = v; }
