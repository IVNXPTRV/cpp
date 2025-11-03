#include "Dog.hpp"

#include <iostream>

static const std::string className = "Dog";
static const std::string animalSound = "Arf! Arf! Arf!";

Dog::Dog() : Animal() {
  this->setType(className);
  std::cout << className << " Default Constructor is called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
  std::cout << className << " Copy Constructor is called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
  std::cout << className << " Copy Assignemnt is called" << std::endl;
  if (this == &other) return *this;
  this->setType(other.getType());
  return *this;
}

Dog::~Dog() { std::cout << className << " Destructor is called" << std::endl; }

void Dog::makeSound() const {
  std::cout << this->getType() << " says " << animalSound << std::endl;
}
