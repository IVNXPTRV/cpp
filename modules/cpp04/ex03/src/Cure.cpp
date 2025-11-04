#include "Cure.hpp"

#include <iostream>

static const std::string className = "Cure";
static const std::string materiaType = "cure";

Cure::Cure() : AMateria(materiaType) {
  std::cout << className << " Default Constructor is called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other.getType()) {
  std::cout << className << " Copy Constructor is called" << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
  std::cout << className << " Copy Assignemnt is called" << std::endl;
  (void)other;
  return *this;
}

Cure::~Cure() {
  std::cout << className << " Destructor is called" << std::endl;
}

AMateria* Cure::clone() const { return (new Cure(*this)); }

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
