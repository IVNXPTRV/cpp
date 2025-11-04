#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

#define MAX_SLOTS 4

class Character : public ICharacter {
 private:
  std::string _name;
  AMateria* _inventory[MAX_SLOTS];
  int _unequipedSize;
  AMateria** _unequipedArray;  // NULL Terminated

  void _deleteUnequipedArray();
  void _deleteInventory();
  void _copyInventory(const Character& src);
  void _addToUnequipedArray(AMateria* item);

 public:
  Character();
  Character(const Character& other);
  Character& operator=(const Character& other);
  virtual ~Character();

  Character(const std::string& name);

  virtual std::string const& getName() const;
  virtual void equip(AMateria* m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter& target);
};

#endif
