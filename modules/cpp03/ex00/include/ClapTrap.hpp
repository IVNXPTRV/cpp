#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
 public:
  ClapTrap();
  ClapTrap(const ClapTrap& other);
  ClapTrap& operator=(const ClapTrap& other);
  ~ClapTrap();

  ClapTrap(std::string name);

  void attack(const std::string&
                  target);  // target lose <damage> of <health>; cost 1 <energy>
  void takeDamage(unsigned int amount);  // *this decrease <health> by <amount>
  void beRepaired(unsigned int amount);  // *this increases <health> by
                                         // <amount>; cost 1 <energy>
  std::string getName() const;
  unsigned int getHealth() const;
  unsigned int getEnergy() const;
  unsigned int getDamage() const;

  void setName(const std::string name);
  void setHealth(const unsigned int amount);
  void setEnergy(const unsigned int amount);
  void setDamage(const unsigned int amount);

  static const std::string model;
  static const std::string defaultName;
  static const unsigned int defaultHealth = 10;
  static const unsigned int defaultEnergy = 10;
  static const unsigned int defaultDamage = 0;

 private:
  std::string _name;
  unsigned int
      _health;  // current health level; if <0> ClapTrap can't do anything
  unsigned int
      _energy;  // avaliable energy points; if <0> ClapTrap can't do anything
  unsigned int _damage;  // attacl damage
};

std::ostream& operator<<(std::ostream& out, const ClapTrap& right);

#endif
