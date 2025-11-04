#include "AMateria.hpp"

#include <iostream>

#include "ICharacter.hpp"

static const std::string className = "AMateria";
static const std::string materiaType = "<unknown>";

AMateria::AMateria() : _type(materiaType) {
  std::cout << className << " Default Constructor is called" << std::endl;
}

AMateria::~AMateria() {
  std::cout << className << " Destructor is called" << std::endl;
}

AMateria::AMateria(std::string const& type) : _type(type) {
  std::cout << className << " Parameterized Constructor is called" << std::endl;
}
const std::string& AMateria::getType() const { return this->_type; }

void AMateria::setType(const std::string& type) { this->_type = type; }

void AMateria::use(ICharacter& target) {
  std::cout << "* An unknown materia is being used against " << target.getName()
            << " *" << std::endl;
}
