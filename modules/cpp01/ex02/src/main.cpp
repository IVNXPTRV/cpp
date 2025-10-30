#include <cstdlib>
#include <iostream>

int main() {
  std::string str = "HI THIS IS BRAIN";
  std::string *stringPTR = &str;
  std::string &stringREF = str;

  std::cout << "Memory address of var: " << &str << std::endl;
  std::cout << "stringPTR holds: " << stringPTR << std::endl;
  std::cout << "stringREF holds: " << &stringREF << std::endl;

  std::cout << std::endl;

  std::cout << "Value of var: " << str << std::endl;
  std::cout << "Dereferenced stringPTR : " << *stringPTR << std::endl;
  std::cout << "Value of stringREF: " << stringREF << std::endl;

  return EXIT_SUCCESS;
}
