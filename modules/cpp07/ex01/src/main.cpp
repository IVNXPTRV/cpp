#include <iostream>

#include "iter.hpp"

int main() {
  int array[] = {0, 1, 2, 3, 4, 5};
  size_t len = 6;

  iter(array, len, printItem<int>);
  std::cout << std::endl;
  iter(array, len, incByOne<int>);
  iter(array, len, printItem<int>);
  std::cout << std::endl;

  const float arrayf[] = {0.1, 1.1, 2.1, 3.1, 4.1, 5.1};
  size_t lenf = 6;

  iter(arrayf, lenf, printItem<const float>);
  std::cout << std::endl;
  // iter(arrayf, lenf, incByOne<float>);
  iter(arrayf, lenf, printItem<const float>);
  std::cout << std::endl;
  return 0;
}

