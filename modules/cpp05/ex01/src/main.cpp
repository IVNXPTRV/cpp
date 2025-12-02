#include <cstdlib>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

void test_default_constructor(std::string name, unsigned int grade) {
  (void)name;
  (void)grade;
  std::cout << "Default constructor test" << std::endl;
  Form b1;
  std::cout << b1 << std::endl;
}

void test_paramed_constructor(std::string name, unsigned int grade) {
  std::cout << "Paramed constructor test" << std::endl;
  Form b1(name, grade, grade + 1);
  std::cout << b1 << std::endl;
}

void test(std::string name, unsigned int grade,
          void (*func)(std::string, unsigned int)) {
  try {
    func(name, grade);
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
  std::cout << std::endl;
}

void test(Bureaucrat b, Form f) {
  std::cout << "Form sign test" << std::endl;
  std::cout << b << std::endl;
  std::cout << f << std::endl;
  b.signForm(f);
  std::cout << f << std::endl;
  std::cout << std::endl;
}

int main() {
  test("", 1, test_default_constructor);

  test("Foo", 1, test_paramed_constructor);
  test("Bar", 150, test_paramed_constructor);
  test("Baz", 149, test_paramed_constructor);
  test("Qux", 200, test_paramed_constructor);
  test("Corge", 10, test_paramed_constructor);

  test(Bureaucrat("Foo", 100), Form("Bar", 101, 102));

  test(Bureaucrat("Foo", 100), Form("Bar", 99, 99));
  return EXIT_SUCCESS;
}
