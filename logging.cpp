#include "logging.hpp"
#include "common.hpp"
#include <iostream>
#include <string>
#include <sstream>

using std::cerr;
using std::endl;
using std::string;
using namespace logger;
using enum logger::messageType;

void Logger::logTo(messageType type, string message, ostream &ostrm,
                   int linenum, string file) {
  switch (type) {
  case DEBUG:
    if (mVerbosity > 3) {
      ostrm << "[" << CmdUtil::colors["green"] << "DEBUG"
            << CmdUtil::colors["end"] << "] on line: " << linenum
            << ", in file: " << file << ": " << message << endl;
    }
    break;
  case INFORMATIVE:
    if (mVerbosity >= 3) {
      ostrm << "[" << CmdUtil::colors["green"] << "INFO"
            << CmdUtil::colors["end"] << "] on line: " << linenum
            << ", in file: " << file << ": " << message << endl;
    }
    break;
  case EDGECASE:
    if (mVerbosity >= 2) {
      ostrm << "[" << CmdUtil::colors["yellow"] << "EDGECASE"
            << CmdUtil::colors["end"] << "] on line: " << linenum
            << ", in file: " << file << ":  " << message << endl;
    }
    break;
  case MINOR_ERROR:
    if (mVerbosity >= 1) {
      ostrm << "[" << CmdUtil::colors["magenta"] << "ERROR"
            << CmdUtil::colors["end"] << "] on line: " << linenum
            << ", in file: " << file << ": " << message << endl;
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
void Logger::log(messageType type, string message, int linenum, string file) {
  this->logTo(type, message, cerr, linenum, file);
}
void Logger::setVerbosity(int v) { this->mVerbosity = v; }
std::string Logger::mTellPos(int linenum, std::string file){
  std::ostringstream strm;
  strm << (linenum!=-1 ? "on line: " : "") << (linenum!=-1 ? std::to_string(linenum) : "") << (file!="" ? " in file: " : "") << (file != "" ? file : "");
  return strm.str();

}
