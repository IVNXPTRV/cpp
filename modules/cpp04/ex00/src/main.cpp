#include <cstdlib>
#include <iostream>

#include "Dog.hpp"

int main() {
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Dog();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();  // will output the cat sound!
  j->makeSound();
  meta->makeSound();
  return EXIT_SUCCESS;
}
