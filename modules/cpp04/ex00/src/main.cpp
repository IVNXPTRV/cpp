#include <cstdlib>
#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();  // will output the cat sound!
  j->makeSound();
  meta->makeSound();
  delete meta;
  delete j;
  delete i;

  std::cout << std::endl;

  const WrongAnimal* wMeta = new WrongAnimal();
  const WrongAnimal* wI = new WrongCat();
  wMeta->makeSound();
  wI->makeSound();
  delete wMeta;
  delete wI;

  return EXIT_SUCCESS;
}
