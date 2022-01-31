#include "common.hpp"
#include <algorithm>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;
/*
             0   to restore default color
             1   for brighter colors
             4   for underlined text
             5   for flashing text
            30   for black foreground
            31   for red foreground
            32   for green foreground
            33   for yellow (or brown) foreground
            34   for blue foreground
            35   for purple foreground
            36   for cyan foreground
            37   for white (or gray) foreground
            40   for black background
            41   for red background
            42   for green background
            43   for yellow (or brown) background
            44   for blue background
            45   for purple background
            46   for cyan background
            47   for white (or gray) background
* */
map<string, string> CmdUtil::colors{{"black", "\x1B[30m"},
                                    {"red", "\x1B[31m"},
                                    {"green", "\x1B[32m"},
                                    {"yellow", "\x1B[33m"},
                                    {"blue", "\x1B[34m"},
                                    {"magenta", "\x1B[35m"},
                                    {"cyan", "\x1B[36m"},
                                    {"white", "\x1B[37m"},
                                    {"end", "\033[0m"},
                                    {"underline", "\x1B[4m"},
                                    {"bg:black", "\x1B[40m"},
                                    {"bg:red", "\x1B[41m"},
                                    {"bg:green", "\x1B[42m"},
                                    {"bg:yellow", "\x1B[43m"},
                                    {"bg:blue", "\x1B[44m"},
                                    {"bg:purple", "\x1B[45m"},
                                    {"bg:cyan", "\x1B[46m"},
                                    {"bg:white", "\x1B[47m"}

};

[[nodiscard]] uint CmdUtil::stringWidth(string s) {

  std::stringstream sstrm(s);
  string line;
  unsigned int longestLen{0u};

  while (std::getline(sstrm, line, '\n')) {
    if (line.length() > longestLen)
      longestLen = line.length();
  }
  return longestLen;
}

[[nodiscard]] string CmdUtil::widestElement(vector<string> strs) noexcept {
  string longest{""};
  for (auto el : strs) {
    if (stringWidth(el) > stringWidth(longest))
      longest = el;
  }
  return longest;
}
[[nodiscard]] uint CmdUtil::stringHeight(string s) noexcept {
  return std::count(s.begin(), s.end(), '\n') + 1;
}
