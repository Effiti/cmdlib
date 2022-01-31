# cmdlib
------------
Cmdlib is a collection of tools to make developing commandline tools in c++ a little bit easier

To use, just link common.cpp and `#include common.hpp` and/or link logging.cpp and `#include logging.hpp`
## NOTES
if you don't want to type `__LINE__, __FILE__` everytime when you want to use logging, you can `#define HERE() __LINE__, FILE__` and use HERE() instead. Might laghter be included to logging.hpp
