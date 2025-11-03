#include "FragTrap.hpp"

#include <iostream>

const std::string FragTrap::defaultModel = "FragTrap";
const std::string FragTrap::defaultName = "FR4G-TP";
const unsigned int FragTrap::defaultHealth = 100;
const unsigned int FragTrap::defaultEnergy = 100;
const unsigned int FragTrap::defaultDamage = 30;

FragTrap::FragTrap() : ClapTrap() {
  setName(defaultName);
  setModel(defaultModel);
  setHealth(defaultHealth);
  setEnergy(defaultEnergy);
  setDamage(defaultDamage);
  std::cout << defaultModel << " Default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap() {
  setName(other.getName());
  setModel(other.getModel());
  setHealth(other.getHealth());
  setEnergy(other.getEnergy());
  setModel(other.getModel());
  std::cout << defaultModel << " Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
  std::cout << defaultModel << " Copy assignment called" << std::endl;
  if (this == &other) return *this;
  setName(other.getName());
  setHealth(other.getHealth());
  setEnergy(other.getEnergy());
  setDamage(other.getDamage());
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << defaultModel << " Destructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap() {
  setName(name);
  setModel(defaultModel);
  setHealth(defaultHealth);
  setEnergy(defaultEnergy);
  setDamage(defaultDamage);
  std::cout << defaultModel << " Parameterized constructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
  std::cout << defaultModel << " " << getName() << " high fives everyone!"
            << std::endl;
}

std::ostream& operator<<(std::ostream& out, const FragTrap& right) {
  out << right.getModel() << " " << right.getName() << ":" << std::endl;
  out << " - Health: " << right.getHealth() << std::endl;
  out << " - Energy: " << right.getEnergy() << std::endl;
  out << " - Damage: " << right.getDamage();
  return out;
}
