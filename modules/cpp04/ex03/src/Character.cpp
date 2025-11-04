#include <iostream>

#include "AMateria.hpp"

static const std::string className = "Character";
static const std::string materiaType = "cure";

Character::Character() : AMateria(materiaType) {
  std::cout << className << " Default Constructor is called" << std::endl;
}

Character::Character(const Character& other) : AMateria(other.getType()) {
  std::cout << className << " Copy Constructor is called" << std::endl;
}

Character& Character::operator=(const Character& other) {
  std::cout << className << " Copy Assignemnt is called" << std::endl;
  (void)other;
  return *this;
}

Character::~Character() {
  std::cout << className << " Destructor is called" << std::endl;
}

AMateria* Character::clone() const { return (new Character(*this)); }

void Character::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
