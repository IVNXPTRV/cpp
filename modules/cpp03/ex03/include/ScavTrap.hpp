#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
 public:
  ScavTrap();
  ScavTrap(const ScavTrap& other);
  ScavTrap& operator=(const ScavTrap& other);
  ~ScavTrap();

  ScavTrap(std::string name);

  static const std::string defaultModel;
  static const std::string defaultName;
  static const unsigned int defaultHealth;
  static const unsigned int defaultEnergy;
  static const unsigned int defaultDamage;

  void attack(
      const std::string& target);  // target lose <damage> of <health>; cost 1
  void guardGate();
};

std::ostream& operator<<(std::ostream& out, const ScavTrap& right);

#endif
