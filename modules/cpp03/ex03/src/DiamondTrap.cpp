#include "DiamondTrap.hpp"

#include <iostream>

#include "ClapTrap.hpp"

const std::string DiamondTrap::defaultModel = "DiamondTrap";
const std::string DiamondTrap::defaultName = "DIA6D-TP";
const unsigned int DiamondTrap::defaultHealth = FragTrap::defaultHealth;
const unsigned int DiamondTrap::defaultEnergy = ScavTrap::defaultEnergy;
const unsigned int DiamondTrap::defaultDamage = FragTrap::defaultDamage;

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
  setName(defaultName);
  setModel(defaultModel);
  setHealth(defaultHealth);
  setEnergy(defaultEnergy);
  setDamage(defaultDamage);
  ClapTrap::_name = defaultName + "_clap_name";
  std::cout << defaultModel << " Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(), ScavTrap(), FragTrap() {
  setName(other.getName());
  setModel(other.getModel());
  setHealth(other.getHealth());
  setEnergy(other.getEnergy());
  setModel(other.getModel());
  ClapTrap::_name = other.getName() + "_clap_name";
  std::cout << defaultModel << " Copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
  std::cout << defaultModel << " Copy assignment called" << std::endl;
  if (this == &other) return *this;
  setName(other.getName());
  setHealth(other.getHealth());
  setEnergy(other.getEnergy());
  setDamage(other.getDamage());
  ClapTrap::_name = other.getName() + "_clap_name";
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << defaultModel << " Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(), FragTrap() {
  setName(name);
  setModel(defaultModel);
  setHealth(defaultHealth);
  setEnergy(defaultEnergy);
  setDamage(defaultDamage);
  ClapTrap::_name = name + "_clap_name";
  std::cout << defaultModel << " Parameterized constructor called" << std::endl;
}

std::string DiamondTrap::getName() const { return _name; };
void DiamondTrap::setName(const std::string name) { _name = name; }

void DiamondTrap::whoAmI(void) {
  std::cout << defaultModel << " " << getName() << " is also known as "
            << ClapTrap::_name << std::endl;
}

std::ostream& operator<<(std::ostream& out, const DiamondTrap& right) {
  out << right.getModel() << " " << right.getName() << ":" << std::endl;
  out << " - Health: " << right.getHealth() << std::endl;
  out << " - Energy: " << right.getEnergy() << std::endl;
  out << " - Damage: " << right.getDamage();
  return out;
}
