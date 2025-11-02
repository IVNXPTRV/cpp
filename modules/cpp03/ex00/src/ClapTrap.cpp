#include "ClapTrap.hpp"

#include <iostream>

const std::string ClapTrap::model = "ClapTrap";
const std::string ClapTrap::defaultName = "CL4P-TP";

ClapTrap::ClapTrap()
    : _name(defaultName),
      _health(defaultHealth),
      _energy(defaultEnergy),
      _damage(defaultDamage) {
  std::cout << model << " Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other.getName()),
      _health(other.getHealth()),
      _energy(other.getEnergy()),
      _damage(other.getDamage()) {
  std::cout << model << " Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
  std::cout << ClapTrap::model << " Copy assignment called" << std::endl;
  if (this == &other) return *this;
  setName(other.getName());
  setHealth(other.getHealth());
  setEnergy(other.getEnergy());
  setDamage(other.getDamage());
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << model << " Destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name),
      _health(defaultHealth),
      _energy(defaultEnergy),
      _damage(defaultDamage) {
  std::cout << model << " Parameterized constructor called" << std::endl;
}

std::string ClapTrap::getName() const { return _name; };

unsigned int ClapTrap::getHealth() const { return _health; }
unsigned int ClapTrap::getEnergy() const { return _energy; }
unsigned int ClapTrap::getDamage() const { return _damage; }

void ClapTrap::setName(const std::string name) { _name = name; }
void ClapTrap::setHealth(const unsigned int amount) { _health = amount; }
void ClapTrap::setEnergy(const unsigned int amount) { _energy = amount; }
void ClapTrap::setDamage(const unsigned int amount) { _damage = amount; }

// ClapTrap <name> attacks <target>, causing <damage> points of damage!
void ClapTrap::attack(const std::string& target) {
  if (getEnergy() == 0 || getHealth() == 0) {
    std::cout << model << getName()
              << " is out of service. Attack is not possible!" << std::endl;
    return;
  }
  std::cout << model << " " << getName() << " attacks " << target;
  std::cout << ", causing " << getDamage() << " points of damage!";
  std::cout << std::endl;
  setEnergy(getEnergy() - 1);
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (amount >= getHealth())
    setHealth(0);  // cap health to 0 if it become negative
  else
    setHealth(getHealth() - amount);
  std::cout << model << " " << getName() << " recieved " << amount
            << " damage, dropping the HP to " << getHealth() << "!"
            << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (getEnergy() == 0 || getHealth() == 0) {
    std::cout << model << getName()
              << " is out of service. Repair is not possible!" << std::endl;
    return;
  }
  setHealth(getHealth() + amount);
  std::cout << model << " " << getName() << " healed " << amount
            << " HP, increasing the HP to " << getHealth() << "!" << std::endl;

  setEnergy(getEnergy() - 1);
}

std::ostream& operator<<(std::ostream& out, const ClapTrap& right) {
  out << right.model << " " << right.getName() << ":" << std::endl;
  out << " - Health: " << right.getHealth() << std::endl;
  out << " - Energy: " << right.getEnergy() << std::endl;
  out << " - Damage: " << right.getDamage();
  return out;
}
