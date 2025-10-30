#include <cstdlib>
#include <iostream>

#include "Zombie.hpp"

int main(int argc, char *argv[]) {
  std::string stackZombie;
  std::string heapZombie;

  if (argc != 3) {
    std::cout << "hint: ./zombie stackRandomChumpName heapNewZombieName"
              << std::endl;
    return EXIT_FAILURE;
  }

  stackZombie = argv[1];
  heapZombie = argv[2];

  std::cout << "\n\t---- Stack Random Chump ----\n\n";
  randomChump(stackZombie);

  std::cout << "\n\t---- Heap New Zombie ----\n\n";
  Zombie *zombie = newZombie(heapZombie);
  zombie->announce();
  delete zombie;
  return EXIT_SUCCESS;
}
