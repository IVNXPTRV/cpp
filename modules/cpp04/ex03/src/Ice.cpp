#include "Ice.hpp"

#include <iostream>

#include "ICharacter.hpp"

static const std::string className = "Ice";
static const std::string materiaType = "ice";

Ice::Ice() : AMateria(materiaType) {
  std::cout << className << " Default Constructor is called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other.getType()) {
  std::cout << className << " Copy Constructor is called" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
  std::cout << className << " Copy Assignemnt is called" << std::endl;
  (void)other;
  return *this;
}

Ice::~Ice() { std::cout << className << " Destructor is called" << std::endl; }

AMateria* Ice::clone() const { return (new Ice(*this)); }

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
