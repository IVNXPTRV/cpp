#include <cstdlib>
#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  std::cout << std::endl << "--- Tests ---" << std::endl;
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  delete j;  // should not create a leak
  delete i;

  // It is not possible
  // Animal();

  return EXIT_SUCCESS;
}
