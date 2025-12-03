#include "Base.hpp"

#include <cstdlib>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base *generate(void) {
  switch (std::rand() % 3) {
    case 0:
      std::cout << "Generated instance of A*\n";
      return (new A());
    case 1:
      std::cout << "Generated instance of B*\n";
      return (new B());
    case 2:
      std::cout << "Generated instance of C*\n";
      return (new C());
    default:
      return (NULL);
  }
}

void identify(Base *p) {
  std::string type = "";
  if (dynamic_cast<A *>(p))
    type = "A";
  else if (dynamic_cast<B *>(p))
    type = "B";
  else if (dynamic_cast<C *>(p))
    type = "C";
  else {
    std::cout << "Unknown type" << std::endl;
    return;
  }
  std::cout << "Identified " << type << " type" << std::endl;
}

void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "Identified A type" << std::endl;
    return;
  } catch (...) {
  }
  try {
    (void)dynamic_cast<B &>(p);
    std::cout << "Identified B type" << std::endl;
    return;
  } catch (...) {
  }
  try {
    (void)dynamic_cast<C &>(p);
    std::cout << "Identified C type" << std::endl;
    return;
  } catch (...) {
  }
  std::cout << "Unknown type" << std::endl;
}
