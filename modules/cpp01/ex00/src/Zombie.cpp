#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie() { std::cout << this->_name << " destroyed." << std::endl; }

void Zombie::announce() {
  std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
