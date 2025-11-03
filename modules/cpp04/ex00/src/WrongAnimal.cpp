#include "WrongAnimal.hpp"

#include <iostream>

static const std::string className = "WrongAnimal";
static const std::string animalSound = "<wrong>#@!";

WrongAnimal::WrongAnimal() : type(className) {
  std::cout << className << " Default Constructor is called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.getType()) {
  std::cout << className << " Copy Constructor is called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
  std::cout << className << " Copy Assignemnt is called" << std::endl;
  if (this == &other) return *this;
  this->setType(other.getType());
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << className << " Destructor is called" << std::endl;
}

std::string WrongAnimal::getType() const { return this->type; }
void WrongAnimal::setType(const std::string& type) { this->type = type; }

void WrongAnimal::makeSound() const {
  std::cout << this->getType() << " says " << animalSound << std::endl;
}
