#pragma once

#include <algorithm>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using uint = unsigned int;

using std::map;
using std::string;
using std::vector;
class CmdUtil {
  public:
  static map<string, string> colors;
  [[nodiscard]] static uint stringWidth(string s);
  [[nodiscard]] static string widestElement(vector<string> strs) noexcept;
  [[nodiscard]] static uint stringHeight(string s) noexcept;
};
