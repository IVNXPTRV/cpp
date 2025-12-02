#include <cstdlib>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void test_default_constructor(std::string name, unsigned int grade) {
  (void)name;
  (void)grade;
  std::cout << "Default constructor test" << std::endl;
  ShrubberyCreationForm b1;
  std::cout << b1 << std::endl;
}

void test_paramed_constructor(std::string name, unsigned int grade) {
  std::cout << "Paramed constructor test" << std::endl;
  (void)name;
  (void)grade;
  ShrubberyCreationForm b1("Bar");
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

void test(Bureaucrat b, AForm &f) {
  std::cout << "Form execute test" << std::endl;
  std::cout << b << std::endl;
  std::cout << f << std::endl;
  b.executeForm(f);
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

  ShrubberyCreationForm f("Bar");
  Bureaucrat b("Foo", 100);
  test(b, f);
  b.signForm(f);
  test(b, f);

  RobotomyRequestForm rf("Baz");
  test(b, rf);
  b.signForm(rf);
  Bureaucrat b1("Qux", 1);
  b1.signForm(rf);
  test(b1, rf);

  PresidentialPardonForm pf("Corge");
  test(b, pf);
  b.signForm(pf);
  b1.signForm(pf);
  test(b1, pf);

  return EXIT_SUCCESS;
}
