#include "MateriaSource.hpp"

#include <iostream>

#include "Character.hpp"
#include "IMateriaSource.hpp"

static const std::string className = "MateriaSource";

MateriaSource::MateriaSource() : IMateriaSource(), _templatesSize(0) {
  for (int i = 0; i < MAX_SLOTS; i++) {
    this->_templates[i] = NULL;
  }
  std::cout << className << " Default Constructor is called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) : IMateriaSource() {
  std::cout << className << " Copy Constructor is called" << std::endl;
  *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
  // std::cout << className << " Copy Assignemnt is called" << std::endl;
  this->_templatesSize = other._templatesSize;
  this->_copyTemplates(other);
  return *this;
}

MateriaSource::~MateriaSource() {
  std::cout << className << " Destructor is called" << std::endl;
}

void MateriaSource::_copyTemplates(const MateriaSource& src) {
  this->_deleteTemplates();
  for (int i = 0; i < MAX_SLOTS; i++) {
    if (src._templates[i] == NULL) {
      this->_templates[i] = NULL;
      continue;
    }
    this->_templates[i] = src._templates[i]->clone();
  }
}

void MateriaSource::_deleteTemplates() {
  for (int i = 0; i < MAX_SLOTS; i++) {
    delete this->_templates[i];
  }
}

void MateriaSource::learnMateria(AMateria* item) {
  if (item == NULL) {
    std::cout << "MateriaSource was not provided with a materia to learn."
              << std::endl;
    return;
  }
  if (this->_templatesSize == MAX_SLOTS) {
    std::cout << "MateriaSource can't learn any more materia." << std::endl;
    return;
  }
  for (int i = 0; i < MAX_SLOTS; i++) {
    if (this->_templates[i] == NULL) {
      this->_templates[i] = item->clone();
      std::cout << "MateriaSource learned the " << item->getType()
                << " materia recipe." << std::endl;
      return;
    }
  }
  return;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
  for (int i = 0; i < MAX_SLOTS; i++) {
    if (this->_templates[i] != NULL && this->_templates[i]->getType() == type) {
      std::cout << "MateriaSource creating " << type << " materia."
                << std::endl;
      return this->_templates[i]->clone();
    }
  }
  std::cout << "MateriaSource does not know the type \"" << type << "\"."
            << std::endl;
  return NULL;
}
