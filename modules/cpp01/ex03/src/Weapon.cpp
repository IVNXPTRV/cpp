#include "Weapon.hpp"

Weapon::Weapon() : _type("") {}
Weapon::Weapon(std::string type) : _type(type) {}
Weapon::~Weapon() {}

void Weapon::setType(std::string type) { this->_type = type; }

const std::string& Weapon::getType() const { return (this->_type); }

Weapon& Weapon::operator=(const Weapon& any) {
  if (this == &any) return *this;
  this->setType(any.getType());
  return *this;
}
