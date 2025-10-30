#include "HumanB.hpp"

#include <iostream>

HumanB::~HumanB() {}

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

void HumanB::setWeapon(Weapon &weapon) { this->_weapon = &weapon; }

void HumanB::attack() {
  std::string type;

  if (this->_weapon != NULL)
    type = this->_weapon->getType();
  else
    type = "<nothing>";
  std::cout << this->_name << " attacks with their " << type << std::endl;
}
