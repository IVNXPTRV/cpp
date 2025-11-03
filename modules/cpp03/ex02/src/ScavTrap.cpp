#include "ScavTrap.hpp"

#include <iostream>

const std::string ScavTrap::defaultModel = "ScavTrap";
const std::string ScavTrap::defaultName = "N-2000";
const unsigned int ScavTrap::defaultHealth = 100;
const unsigned int ScavTrap::defaultEnergy = 50;
const unsigned int ScavTrap::defaultDamage = 20;

ScavTrap::ScavTrap() : ClapTrap() {
  setName(defaultName);
  setModel(defaultModel);
  setHealth(defaultHealth);
  setEnergy(defaultEnergy);
  setDamage(defaultDamage);
  std::cout << defaultModel << " Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap() {
  setName(other.getName());
  setModel(other.getModel());
  setHealth(other.getHealth());
  setEnergy(other.getEnergy());
  setModel(other.getModel());
  std::cout << defaultModel << " Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
  std::cout << defaultModel << " Copy assignment called" << std::endl;
  if (this == &other) return *this;
  setName(other.getName());
  setHealth(other.getHealth());
  setEnergy(other.getEnergy());
  setDamage(other.getDamage());
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << defaultModel << " Destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap() {
  setName(name);
  setModel(defaultModel);
  setHealth(defaultHealth);
  setEnergy(defaultEnergy);
  setDamage(defaultDamage);
  std::cout << defaultModel << " Parameterized constructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
  if (getEnergy() == 0 || getHealth() == 0) {
    std::cout << defaultModel << getName()
              << " is out of service. Attack is not possible!" << std::endl;
    return;
  }
  std::cout << defaultModel << " " << getName() << " attacks " << target;
  std::cout << ", causing " << getDamage() << " points of damage!";
  std::cout << std::endl;
  setEnergy(getEnergy() - 1);
}

void ScavTrap::guardGate(void) {
  std::cout << defaultModel << " " << getName() << " is in gatekeeping mode!"
            << std::endl;
}

std::ostream& operator<<(std::ostream& out, const ScavTrap& right) {
  out << right.getModel() << " " << right.getName() << ":" << std::endl;
  out << " - Health: " << right.getHealth() << std::endl;
  out << " - Energy: " << right.getEnergy() << std::endl;
  out << " - Damage: " << right.getDamage();
  return out;
}
