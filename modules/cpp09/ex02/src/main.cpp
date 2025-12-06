
#include <cstdlib>
#include <deque>
#include <vector>

#include "PmergeMe.hpp"

int main(const int argc, const char **argv) {
  try {
    if (argc < 2) throw "Error: wrong input";
    sort<std::vector, int>(argv + 1, true);
    sort<std::deque, int>(argv + 1, false);
  } catch (const char *str) {
    std::cerr << str << std::endl;
    // return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
