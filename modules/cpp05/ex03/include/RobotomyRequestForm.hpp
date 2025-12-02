#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
 private:
  std::string _target;

 public:
  static int const gradeToSign = 72;
  static int const gradeToExecute = 45;

 public:
  RobotomyRequestForm();
  virtual ~RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm& other);
  RobotomyRequestForm(const std::string& target);

  RobotomyRequestForm& operator=(const RobotomyRequestForm& right);

  std::string const getTarget() const;
  virtual void beExecuted() const;
};

#endif
