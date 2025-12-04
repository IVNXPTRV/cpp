
#include <cstdlib>

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
  if (argc != 2) return EXIT_FAILURE;
  BitcoinExchange::calculate(argv[1]);
  return EXIT_SUCCESS;
}
