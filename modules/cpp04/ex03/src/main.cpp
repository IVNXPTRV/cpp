#include <cstdlib>
#include <iostream>

#include "Character.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void testMateriaSource() {
  MateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Ice());
  src->learnMateria(new Ice());
  src->learnMateria(new Ice());
  src->learnMateria(new Ice());
  src->learnMateria(new Ice());
  src->learnMateria(new Ice());

  AMateria* tmp;
  tmp = src->createMateria("cure");

  src->learnMateria(new Cure());
  AMateria* tmp1;
  tmp1 = src->createMateria("cure");
  src->createMateria("#@!");

  MateriaSource src1(*src);

  src1 = *src;
  std::cout << std::endl;
  delete tmp;
  delete tmp1;
  delete src;
}

void testCharacter() {
  Character* me = new Character("me");
  Character* bob = new Character("bob");

  me->equip(new Ice());
  me->equip(new Ice());
  me->equip(new Ice());
  me->equip(new Ice());
  me->equip(new Ice());
  me->equip(new Ice());
  me->equip(new Ice());
  me->use(0, *bob);
  me->unequip(0);
  me->unequip(0);
  me->unequip(10);

  Character foo(*me);

  foo = *bob;

  std::cout << std::endl;
  delete me;
  delete bob;
}

void testSubject() {
  std::cout << std::endl << "--- Subject Tests ---" << std::endl;

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
}

int main() {
  // testSubject();
  testMateriaSource();
  // testCharacter();
  return EXIT_SUCCESS;
}
