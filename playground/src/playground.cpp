
#include <stdlib.h>

#include <ctime>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

int main(void) {
  std::string str = "100001111";
  std::string str1(str);

  str.append(1, '0');
  str1.erase(str1.length() - 2);
  std::cout << str << std::endl;
  std::cout << str1 << std::endl;

  return (EXIT_SUCCESS);
}
