#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include <cstdlib>
#include <string>

class Zombie {
 public:
  Zombie(void);
  Zombie(std::string name);
  ~Zombie();
  void announce(void);
  void setName(std::string name);

 private:
  std::string _name;
};

Zombie *zombieHorde(int N, std::string name);

#endif  // ZOMBIE_H_
