#include <cstdlib>
#include <iostream>

#include "Harl.hpp"

bool isValidInput(int argc) {
  if (argc != 2) {
    std::cout << "Usage: ./harl level" << std::endl;
    return false;
  }
  return true;
}

void complain(Harl &harl, const std::string &level) {
  std::cout << "[ " << level << " ]" << std::endl;
  harl.complain(level);
}

void harlFilter(Harl &harl, const std::string &level) {
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  int index = -1;
  for (int i = 0; i < 4; i++)
    if (levels[i] == level) index = i;
  switch (index) {
    case 0:
      complain(harl, levels[0]);
      // fallthrough
    case 1:
      complain(harl, levels[1]);
      // fallthrough
    case 2:
      complain(harl, levels[2]);
      // fallthrough
    case 3:
      complain(harl, levels[3]);
      // fallthrough
      break;
    default:
      std::cout << "[ Probably complaining about insignificant problems ]"
                << std::endl;
  }
}

int main(int argc, char *argv[]) {
  Harl harl;

  if (!isValidInput(argc)) {
    return EXIT_FAILURE;
  }
  harlFilter(harl, argv[1]);
  return EXIT_SUCCESS;
}
