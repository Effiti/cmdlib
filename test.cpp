#include "common.hpp"
#include "logging.hpp"

int main(int argc, char **argv) {
  logger::Logger l{5};
  if (argc <= 1)
    l.log(logger::messageType::EDGECASE, "No arguments provided!!", HERE);
  return 0;
}
