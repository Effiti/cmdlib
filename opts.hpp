#pragma once

#include "common.hpp"

enum class optTypes { TOGGLE, ARGUMENT };

class Option {
public:
  Option(optTypes t, std::string longFlag,
         std::variant<std::string, std::monostate> shortFlag)
      : mOptType{t}, mLongFlag{longFlag}, mShortFlag{shortFlag} {};
  std::variant<std::string, std::monostate> getShortFlag() {
    return mShortFlag;
  };
  std::string getLongFlag() { return mLongFlag; };

private:
  optTypes mOptType;
  std::string mLongFlag;
  std::variant<std::string, std::monostate> mShortFlag;
};

class Options {
public:
  Options(std::vector<Option> opts) : mOpts{opts} {};
  std::map<std::string, std::variant<std::string, bool>> map();

private:
  std::vector<Option> mOpts;
};

class ParsedOptions {
public:
  ParsedOptions();
  std::variant<std::string, bool, std::monostate> get(std::string flagName);

private:
  std::map<std::string, std::variant<std::string, bool>> mValues;
};

class OptionParser {};
