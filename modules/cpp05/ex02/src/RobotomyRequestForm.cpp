#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

static const std::string defaultName = "Robotomy Creation Form";
static const unsigned int defaultGradeRequiredToSign =
    RobotomyRequestForm::gradeToSign;
static const unsigned int defaultGradeRequiredToExecute =
    RobotomyRequestForm::gradeToExecute;
static const std::string defaultTarget = "Roboto Target";

RobotomyRequestForm::RobotomyRequestForm()
    : AForm(defaultName, defaultGradeRequiredToSign,
            defaultGradeRequiredToExecute),
      _target(defaultTarget) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other)
    : AForm(other), _target(defaultTarget) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm(defaultName, defaultGradeRequiredToSign,
            defaultGradeRequiredToExecute),
      _target(target) {}

void RobotomyRequestForm::beExecuted() const {
  std::cout << "* kzzzzt... drilling noises... bip bip bip... clang! *"
            << std::endl;
  if (std::rand() % 2)
    std::cout << this->_target << " successfully robotomized!" << std::endl;
  else
    std::cout << "Oh no! " << this->_target << " resisted robotomization..."
              << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& other) {
  if (this == &other) return *this;
  this->_target = other._target;
  return *this;
}
