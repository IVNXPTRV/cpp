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

 private:
  std::string _name;
};

Zombie* newZombie(std::string name);

void randomChump(std::string name);

#endif  // ZOMBIE_H_
