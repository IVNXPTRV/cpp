#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
 public:
  FragTrap();
  FragTrap(const FragTrap& other);
  FragTrap& operator=(const FragTrap& other);
  ~FragTrap();

  FragTrap(std::string name);

  static const std::string defaultModel;
  static const std::string defaultName;
  static const unsigned int defaultHealth;
  static const unsigned int defaultEnergy;
  static const unsigned int defaultDamage;

  void highFivesGuys(void);
};

std::ostream& operator<<(std::ostream& out, const FragTrap& right);

#endif
