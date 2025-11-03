#include "WrongCat.hpp"

#include <iostream>

static const std::string className = "WrongCat";
static const std::string animalSound = "Meowwwww";

WrongCat::WrongCat() : WrongAnimal() {
  this->setType(className);
  std::cout << className << " Default Constructor is called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
  std::cout << className << " Copy Constructor is called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
  std::cout << className << " Copy Assignemnt is called" << std::endl;
  if (this == &other) return *this;
  this->setType(other.getType());
  return *this;
}

WrongCat::~WrongCat() {
  std::cout << className << " Destructor is called" << std::endl;
}

void WrongCat::makeSound() const {
  std::cout << this->getType() << " says " << animalSound << std::endl;
}
