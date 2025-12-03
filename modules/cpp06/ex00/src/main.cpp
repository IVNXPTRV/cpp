#include "ScalarConverter.hpp"

// static void test(const std::string testname, const std::string str){
//   std::cout << "test: " << testname << std::endl;
//   std::cout << "input: " << str << std::endl;
//   ScalarConverter::convert(str);
//   std::cout << std::endl;
// }

// int main() {

//   test("Printable Char", "*");
//   test("Two Printable Chars", "**");
//   test("Test 1", "-*");
//   test("Positive int", "42");
//   test("Negative int", "-42");
//   test("Float notation", "42.0f");
//   test("Float notation", "42.3f");
//   test("Large Double", "100000000000000000000000000000000");
//   test("Char Overflow", "256");
//   test("Int Overflow", "2147483648");
//   test("Float Overflow", "3400000000000000000000000000000000000000");
//   test("Double Overflow",
//   "10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
//   test("-inff", "-inff");
//   test("+inff", "+inff");
//   test("nanf", "nanf");
//   test("-inf", "-inf");
//   test("+inf", "+inf");
//   test("Typo in nanff", "nanff");
//   return EXIT_SUCCESS;
// }

int main(int argc, char **argv) {
  if (argc < 2)
    std::cout << argv[0] << " input" << std::endl;
  else
    ScalarConverter::convert(argv[1]);
  return EXIT_SUCCESS;
}
