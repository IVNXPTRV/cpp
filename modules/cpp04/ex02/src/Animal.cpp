#include "Animal.hpp"

#include <iostream>

static const std::string className = "Animal";
static const std::string animalSound = "#@!";

Animal::Animal() : type(className) {
  std::cout << className << " Default Constructor is called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.getType()) {
  std::cout << className << " Copy Constructor is called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
  std::cout << className << " Copy Assignemnt is called" << std::endl;
  if (this == &other) return *this;
  this->setType(other.getType());
  return *this;
}

Animal::~Animal() {
  std::cout << className << " Destructor is called" << std::endl;
}

std::string Animal::getType() const { return this->type; }
void Animal::setType(const std::string& type) { this->type = type; }

void Animal::makeSound() const {
  std::cout << this->getType() << " says " << animalSound << std::endl;
}
