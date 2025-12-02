#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Intern {
 private:
  class InvalidFormName : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  AForm *makePresidentialForm(const std::string &target);
  AForm *makeRobotomyForm(const std::string &target);
  AForm *makeShrubberyForm(const std::string &target);

 public:
  Intern();
  ~Intern();
  Intern(const Intern &other);

  Intern &operator=(const Intern &right);

  AForm *makeForm(const std::string formName, const std::string target);
  AForm *bakeForm(const std::string formName, const std::string target);
};

#endif
