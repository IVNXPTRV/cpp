#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <string>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
 public:
  DiamondTrap();
  DiamondTrap(const DiamondTrap& other);
  DiamondTrap& operator=(const DiamondTrap& other);
  ~DiamondTrap();

  DiamondTrap(std::string name);

  std::string getName() const;
  void setName(const std::string name);

  static const std::string defaultModel;
  static const std::string defaultName;
  static const unsigned int defaultHealth;
  static const unsigned int defaultEnergy;
  static const unsigned int defaultDamage;

  void whoAmI();

  using ScavTrap::attack;

 private:
  std::string _name;
};

std::ostream& operator<<(std::ostream& out, const DiamondTrap& right);

#endif
