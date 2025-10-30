#include <cstdlib>
#include <iostream>
#include <sstream>

#include "Zombie.hpp"

bool stoi(std::string str, int &size) {
  std::stringstream ss(str);
  ss >> size;
  return (!ss.fail() && ss.eof());
}

int main(int argc, char *argv[]) {
  int hordeSize;
  Zombie *horde;

  if (argc < 3 || !stoi(argv[1], hordeSize)) {
    std::cout << "hint: ./zombie hordeSize nameOfZombie" << std::endl;
    return EXIT_FAILURE;
  }
  horde = zombieHorde(hordeSize, argv[2]);
  delete[] horde;
  return EXIT_SUCCESS;
}
