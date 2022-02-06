#include "opts.hpp"
#include <variant>

std::variant<std::string, bool, std::monostate> ParsedOptions::get(std::string key){
  if(mValues.count(key)) {
    if (std::holds_alternative<bool>(mValues[key]))
      return std::get<bool>(mValues[key]);
    else
      return std::get<std::string>(mValues[key]);
  }
  else {
    return std::monostate();
  }

}
