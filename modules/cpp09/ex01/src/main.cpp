
#include <cstdlib>

#include "RPN.hpp"

int main(int argc, char **argv) {
  if (argc != 2) return EXIT_FAILURE;
  calculate(argv[1]);
  return EXIT_SUCCESS;
}
