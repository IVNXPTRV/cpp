#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Base.hpp"

int main() {
  Base* p;
  std::srand(std::time(NULL));
  // p = generate();
  // (void)p;
  // identify(p);
  for (int i = 0; i < 25; i++) {
    std::cout << "Test [" << i << "]:";
    p = generate();
    identify(p);
    identify(*p);
    delete (p);
    std::cout << std::endl;
  }
  std::cout << "Wrong type test" << std::endl;
  p = NULL;
  identify(p);
  // identify(*p);
  return EXIT_SUCCESS;
}
