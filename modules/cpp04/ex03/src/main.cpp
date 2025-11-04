#include <cstdlib>
#include <iostream>

#include "Character.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void testMateriaSource() {
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Ice());
  // src->learnMateria(new Ice());
  // src->learnMateria(new Ice());
  // src->learnMateria(new Ice());
  // src->learnMateria(new Ice());
  // src->learnMateria(new Ice());

  AMateria* tmp;
  tmp = src->createMateria("cure");

  src->learnMateria(new Cure());
  AMateria* tmp1;
  tmp1 = src->createMateria("cure");
  src->createMateria("#@!");

  std::cout << std::endl;
  delete tmp;
  delete tmp1;
  delete src;
}

void testCharacter() {
  ICharacter* me = new Character("me");
  ICharacter* bob = new Character("bob");

  me->equip(new Ice());
  me->use(0, *bob);

  std::cout << std::endl;
  delete me;
  delete bob;
}

int main() {
  std::cout << std::endl << "--- Tests ---" << std::endl;

  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter* me = new Character("me");

  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);

  ICharacter* bob = new Character("bob");

  me->use(0, *bob);
  me->use(1, *bob);

  delete bob;
  delete me;
  delete src;

  // testMateriaSource();
  // testCharacter();
  return EXIT_SUCCESS;
}
