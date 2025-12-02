#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class ShrubberyCreationForm: public AForm {
  private:
    std::string _target;

  public:
    static int const	gradeToSign = 145;
    static int const	gradeToExecute = 137;

  public:
    ShrubberyCreationForm();
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm(const std::string& target); 
  
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& right);

    std::string const getTarget() const;
    virtual void beExecuted() const;
};

#endif
