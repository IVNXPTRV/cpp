#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

template <typename T>
void test(const std::string &name, T &c, const int &i) {
  std::cout << name << " container test" << std::endl;
  c.push_back(0);
  c.push_back(1);
  c.push_back(2);
  c.push_back(3);
  try {
    typename T::const_iterator it = easyfind(c, i);
    (void)it;
    std::cout << i << " has been found" << std::endl;
  } catch (const std::exception &e) {
    std::cout << i << " has not been found" << std::endl;
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> vector;
  std::list<int> list;
  std::deque<int> deque;

  test("vector", vector, 0);
  test("list", list, 1);
  test("deque", deque, 2);

  test("deque", deque, -1);
}
