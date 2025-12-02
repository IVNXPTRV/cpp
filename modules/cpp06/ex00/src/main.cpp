#include "ScalarConverter.hpp"



static void test(const std::string testname, const std::string str){
  std::cout << "test: " << testname << std::endl;
  std::cout << "input: " << str << std::endl;
  ScalarConverter::convert(str);
  std::cout << std::endl;
}

int main() {
  test("Printable Char", "42.0f");
  test("Printable Char", "*");
  test("Double Overflow", "1000000000000000000000000000000000000000000000000000000000000");
  return EXIT_SUCCESS;
}
