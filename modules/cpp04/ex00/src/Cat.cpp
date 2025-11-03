#include "Cat.hpp"

#include <iostream>

static const std::string className = "Cat";
static const std::string animalSound = "Meowwwww";

Cat::Cat() : Animal() {
  this->setType(className);
  std::cout << className << " Default Constructor is called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
  std::cout << className << " Copy Constructor is called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
  std::cout << className << " Copy Assignemnt is called" << std::endl;
  if (this == &other) return *this;
  this->setType(other.getType());
  return *this;
}

Cat::~Cat() { std::cout << className << " Destructor is called" << std::endl; }

void Cat::makeSound() const {
  std::cout << this->getType() << " says " << animalSound << std::endl;
}
