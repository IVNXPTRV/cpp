#include <cstdlib>
#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  std::cout << std::endl << "--- Subject Example ---" << std::endl;
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  delete j;  // should not create a leak
  delete i;

  std::cout << std::endl
            << "--- Call Destructors via Animal in an Array --" << std::endl;
  Animal* animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
  for (int i = 0; i < 4; i++) delete animals[i];

  std::cout << std::endl
            << "--- Check if Copy Constructor makes Deep Copy --" << std::endl;
  Cat* cat0 = new Cat();
  Cat* cat1 = new Cat(*cat0);
  std::cout << cat0->getBrain() << " - memory adress of the cat0 brain"
            << std::endl;
  std::cout << cat1->getBrain() << " - memory adress of the cat1 brain"
            << std::endl;
  std::cout << cat0->getBrain()->getIdea(0) << " - a first idea in cat0 brain"
            << std::endl;
  std::cout << cat1->getBrain()->getIdea(0) << " - a first idea in cat1 brain"
            << std::endl;
  std::cout << &(cat0->getBrain()->getIdea(0))
            << " - an address of a first idea in cat0 brain" << std::endl;
  std::cout << &(cat1->getBrain()->getIdea(0))
            << " - an address of a first idea in cat1 brain" << std::endl;
  delete cat0;
  delete cat1;

  return EXIT_SUCCESS;
}
