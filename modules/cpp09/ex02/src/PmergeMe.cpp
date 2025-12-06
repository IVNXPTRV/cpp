#include "PmergeMe.hpp"

void swap(int& a, int& b) {
  int tmp = 0;

  tmp = a;
  a = b;
  b = tmp;
}

void generateJacobsthalSequence(std::vector<size_t>& vec) {
  for (size_t i = 0; i < vec.size(); i++)
    vec[i] = (pow(2, i + 2) - pow(-1, i + 2)) / 3;
}
