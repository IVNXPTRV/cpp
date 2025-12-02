#include "PresidentialPardonForm.hpp"

#include <cstdlib>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

static const std::string defaultName = "Presidential Pardon Form";
static const unsigned int defaultGradeRequiredToSign =
    PresidentialPardonForm::gradeToSign;
static const unsigned int defaultGradeRequiredToExecute =
    PresidentialPardonForm::gradeToExecute;
static const std::string defaultTarget = "Pardon Target";

PresidentialPardonForm::PresidentialPardonForm()
    : AForm(defaultName, defaultGradeRequiredToSign,
            defaultGradeRequiredToExecute),
      _target(defaultTarget) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const& other)
    : AForm(other), _target(defaultTarget) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm(defaultName, defaultGradeRequiredToSign,
            defaultGradeRequiredToExecute),
      _target(target) {}

void PresidentialPardonForm::beExecuted() const {
  std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& other) {
  if (this == &other) return *this;
  this->_target = other._target;
  return *this;
}
