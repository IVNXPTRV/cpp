#include <cstdlib>
#include <iostream>

#include "Harl.hpp"

bool isValidInput(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Usage: ./harl level" << std::endl;
    return false;
  }
  std::string arg(argv[1]);
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  for (int i = 0; i < 4; i++) {
    if (arg == levels[i]) return true;
  }
  std::cout << "Usage: ./harl DEBUG|INFO|WARNING|ERROR" << std::endl;
  return false;
}

int main(int argc, char *argv[]) {
  Harl harl;

  if (!isValidInput(argc, argv)) {
    return EXIT_FAILURE;
  }
  harl.complain(argv[1]);
  return EXIT_SUCCESS;
}
