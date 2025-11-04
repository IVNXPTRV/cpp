#include "Character.hpp"

#include <iostream>

static const std::string className = "Character";
static const std::string defaultName = "<defaultName>";

Character::Character()
    : ICharacter(),
      _name(defaultName),
      _unequipedSize(0),
      _unequipedArray(NULL) {
  for (int i = 0; i < MAX_SLOTS; i++) {
    this->_inventory[i] = NULL;
  }
  std::cout << className << " Default Constructor is called" << std::endl;
}

Character::Character(const Character& other)
    : ICharacter(),
      _name(other.getName()),
      _unequipedSize(0),
      _unequipedArray(NULL) {
  std::cout << className << " Copy Constructor is called" << std::endl;
  for (int i = 0; i < MAX_SLOTS; i++) {
    this->_inventory[i] = NULL;
  }
  this->_copyInventory(other);
}

Character& Character::operator=(const Character& other) {
  std::cout << className << " Copy Assignemnt is called" << std::endl;
  if (this == &other) return *this;
  this->_name = other.getName();
  this->_copyInventory(other);
  this->_deleteUnequipedArray();
  return *this;
}

Character::~Character() {
  this->_deleteUnequipedArray();
  this->_deleteInventory();
  std::cout << className << " Destructor is called" << std::endl;
}
Character::Character(const std::string& name)
    : ICharacter(), _name(name), _unequipedSize(0), _unequipedArray(NULL) {
  for (int i = 0; i < MAX_SLOTS; i++) {
    this->_inventory[i] = NULL;
  }
  std::cout << className << " Parameterized Constructor is called" << std::endl;
}

void Character::_deleteUnequipedArray() {
  if (this->_unequipedArray == NULL) return;
  for (int i = 0; i < this->_unequipedSize; i++) {
    delete this->_unequipedArray[i];
    this->_unequipedArray[i] = NULL;
  }
  delete[] this->_unequipedArray;
  this->_unequipedArray = NULL;
}

void Character::unequip(int idx) {
  if (idx < 0 || idx >= MAX_SLOTS) {
    std::cout << this->_name
              << ": I can't unequip anything from inventory index " << idx
              << ". It's not a valid index!" << std::endl;
    return;
  }
  if (this->_inventory[idx] == NULL) {
    std::cout << this->_name << ": I don't have anything at index " << idx
              << " to unequip!" << std::endl;
    return;
  }
  this->_addToUnequipedArray(this->_inventory[idx]);
  this->_inventory[idx] = NULL;
}

void Character::_addToUnequipedArray(AMateria* item) {
  AMateria** tmp;
  tmp = this->_unequipedArray;
  this->_unequipedArray = new AMateria*[this->_unequipedSize + 1];
  for (int i = 0; i < this->_unequipedSize; i++) {
    this->_unequipedArray[i] = tmp[i];
  }
  this->_unequipedArray[this->_unequipedSize] = item;
  this->_unequipedSize += 1;
  delete[] tmp;
  tmp = NULL;
}

void Character::_copyInventory(const Character& src) {
  this->_deleteInventory();
  for (int i = 0; i < MAX_SLOTS; i++) {
    if (src._inventory[i] == NULL) {
      this->_inventory[i] = NULL;
    } else {
      this->_inventory[i] = src._inventory[i]->clone();
    }
  }
}

void Character::_deleteInventory() {
  for (int i = 0; i < MAX_SLOTS; i++) {
    delete this->_inventory[i];
    this->_inventory[i] = NULL;
  }
}

void Character::equip(AMateria* m) {
  for (int i = 0; i < MAX_SLOTS; i++) {
    if (this->_inventory[i] == NULL) {
      this->_inventory[i] = m;
      std::cout << this->_name << ": equiped " << m->getType() << std::endl;
      return;
    }
  }
  std::cout << this->_name << ": inventory is full. Cannot equip "
            << m->getType() << std::endl;
  delete m;
}

void Character::use(int idx, ICharacter& target) {
  if (idx < 0 || idx >= MAX_SLOTS) {
    std::cout << this->_name << ": I can't use anything from inventory index "
              << idx << ". It's not a valid index!" << std::endl;
    return;
  }
  if (this->_inventory[idx] == NULL) {
    std::cout << this->_name << ": I don't have anything at index " << idx
              << " to use!" << std::endl;
    return;
  }
  this->_inventory[idx]->use(target);
}

std::string const& Character::getName() const { return this->_name; }
