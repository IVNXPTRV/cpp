#include <cstdlib>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
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
  {
    Intern someRandomIntern;
    AForm *rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << rrf->getName() << std::endl;
    (void)rrf;
    delete rrf;
  }
  {
    Intern someRandomIntern;
    AForm *rrf;
    rrf = someRandomIntern.makeForm("unexisting form", "Bender");
    (void)rrf;
  }
  {
    Intern someRandomIntern;
    AForm *rrf;
    rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    std::cout << rrf->getName() << std::endl;
    (void)rrf;
    delete rrf;
  }
  return EXIT_SUCCESS;
}
