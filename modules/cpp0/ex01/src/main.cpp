
#include <cstdlib>
#include <iostream>

int main(int argc, char **argv) {
  std::string line;

  if (argc == 1) {
    line = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << line;
  }
  while (*++argv) {
    line = *argv;
    for (size_t i = 0; i < line.length(); i++) line[i] = std::toupper(line[i]);
    std::cout << line << " ";
  }
  std::cout << std::endl;
  return (EXIT_SUCCESS);
}
