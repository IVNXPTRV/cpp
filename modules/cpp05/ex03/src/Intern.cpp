#include "Intern.hpp"

#include <cstdlib>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(Intern const &other) { (void)other; }

AForm *Intern::makePresidentialForm(const std::string &target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomyForm(const std::string &target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::makeShrubberyForm(const std::string &target) {
  return new ShrubberyCreationForm(target);
}

const char *Intern::InvalidFormName::what() const throw() {
  return "Invalid form name.";
}

AForm *Intern::makeForm(const std::string formName, const std::string target) {
  try {
    AForm *form = bakeForm(formName, target);
    std::cout << "Intern creates " << formName << std::endl;
    return form;
  } catch (const std::exception &e) {
    std::cout << "Intern failed to create " << formName << " because "
              << e.what() << std::endl;
  }
  return NULL;
}

AForm *Intern::bakeForm(const std::string formName, const std::string target) {
  AForm *(Intern::*factory[3])(const std::string &) = {
      &Intern::makePresidentialForm, &Intern::makeRobotomyForm,
      &Intern::makeShrubberyForm};
  std::string names[3] = {"presidential pardon", "robotomy request",
                          "shrubbery creation"};
  for (int i = 0; i < 3; i++)
    if (formName == names[i]) {
      return ((this->*factory[i])(target));
    }
  throw Intern::InvalidFormName();
}

Intern &Intern::operator=(const Intern &other) {
  if (this == &other) return *this;
  return *this;
}
