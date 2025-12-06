
#include <cstdlib>
#include <deque>
#include <vector>

#include "PmergeMe.hpp"

int main(const int argc, const char **argv) {
  if (argc < 2) return EXIT_FAILURE;
  sort<std::vector, int>(argv + 1);
  return EXIT_SUCCESS;
}
