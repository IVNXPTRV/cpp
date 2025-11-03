#include <cstdlib>
#include <iostream>

#include "ScavTrap.hpp"

int main() {
  ScavTrap trap0("Foo");
  ScavTrap trap1("Bar");

  trap0.beRepaired(0);
  trap0.attack(trap1.getName());
  trap1.takeDamage(ScavTrap::defaultDamage);
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
  trap0.takeDamage(10000);
  std::cout << trap0 << std::endl;
  trap0.takeDamage(101111);
  std::cout << trap0 << std::endl;
  trap0.beRepaired(100);
  std::cout << trap0 << std::endl;

  ScavTrap trap2;
  std::cout << trap2 << std::endl;
  ScavTrap trap3;
  trap3.setName("Waz");
  trap2 = trap3;
  std::cout << trap2 << std::endl;
  std::cout << trap3 << std::endl;

  ScavTrap trap4("Child");
  ClapTrap *ptr = &trap4;
  (void)ptr;
  return EXIT_SUCCESS;
}
