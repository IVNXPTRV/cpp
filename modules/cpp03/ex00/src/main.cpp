#include <cstdlib>
#include <iostream>

#include "ClapTrap.hpp"

int main() {
  ClapTrap trap0("Foo");
  ClapTrap trap1("Bar");

  trap0.beRepaired(0);
  trap0.attack(trap1.getName());
  trap1.takeDamage(ClapTrap::defaultDamage);
  trap0.attack(trap1.getName());
  trap1.takeDamage(5);
  trap1.beRepaired(4);
  trap1.attack(trap0.getName());
  trap0.takeDamage(5);
  trap0.beRepaired(5000);
  trap1.beRepaired(5000);
  std::cout << trap1 << std::endl;
  trap1.attack(trap1.getName());
  trap1.attack(trap1.getName());
  trap1.attack(trap1.getName());
  trap1.attack(trap1.getName());
  trap1.attack(trap1.getName());
  trap1.attack(trap1.getName());
  trap1.takeDamage(5000);
  trap1.beRepaired(5000);
  trap1.takeDamage(1);
  trap1.attack(trap1.getName());
  std::cout << trap1 << std::endl;
  std::cout << trap0 << std::endl;
  return EXIT_SUCCESS;
}
