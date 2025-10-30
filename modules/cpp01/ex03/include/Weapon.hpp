#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
 public:
  Weapon();
  ~Weapon();
  Weapon(std::string type);

  void setType(std::string type);
  const std::string& getType() const;

  Weapon& operator=(const Weapon& any);

 private:
  std::string _type;
};

#endif  // WEAPON_HPP
