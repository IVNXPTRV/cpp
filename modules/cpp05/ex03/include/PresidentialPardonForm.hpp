#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
 private:
  std::string _target;

 public:
  static int const gradeToSign = 25;
  static int const gradeToExecute = 5;

 public:
  PresidentialPardonForm();
  virtual ~PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm& other);
  PresidentialPardonForm(const std::string& target);

  PresidentialPardonForm& operator=(const PresidentialPardonForm& right);

  std::string const getTarget() const;
  virtual void beExecuted() const;
};

#endif
