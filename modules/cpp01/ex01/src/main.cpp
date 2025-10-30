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
  int hordeSize = 0;
  Zombie *horde = NULL;

  if (argc != 3 || !stoi(argv[1], hordeSize) || hordeSize <= 0) {
    std::cout << "hint: ./zombie 'hordeSize > 0' 'nameOfZombie'" << std::endl;
    return EXIT_FAILURE;
  }
  horde = zombieHorde(hordeSize, argv[2]);
  for (int i = 0; i < hordeSize; i++) {
    horde[i].announce();
  }
  delete[] horde;
  return EXIT_SUCCESS;
}
