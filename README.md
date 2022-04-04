# cmdlib
------------
Cmdlib is a collection of tools to make developing commandline tools in c++ a little bit easier

To use, just link common.cpp and `#include common.hpp` and/or link logging.cpp and `#include logging.hpp`
## EXAMPLES
The most basic usecase for the logging library would be something like this:
```c++
const int verbosity = 5;
logger::Logger l{ verbosity };
int main(void) {
  l.log(logger::messageType::INFORMATIVE, "Hello World!", __LINE__ __FILE__);
}
``` 
you could also imagine something like this:
```c++
#ifdef DEBUG
  const int verbosity = 5;
#else
  const int verbosity = 1
#endif
logger::Logger l{ verbosity };
int main(void) {
  l.log(logger::messageType::INFORMATIVE, "Hello World!", __LINE__ __FILE__);
}
```


## NOTES
if you don't want to type `__LINE__, __FILE__` everytime when you want to use logging, you can use HERE instead.
