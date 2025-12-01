#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;
class Form {
  // Private Attributes
 private:
  const std::string _name;
  const unsigned int _gradeRequiredToSign;
  const unsigned int _gradeRequiredToExecute;
  bool _isSigned;

  // Public Attributes
 public:
  // Private Methods
 private:
  // Logic
  void confirmValidGrade(unsigned int grade);

  // Exceptions
  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class AlreadySignedException : public std::exception {
   public:
    virtual const char* what(void) const throw();
  };

  // Public Methods
 public:
  // Constructors and Destructors
  Form();
  ~Form();
  Form(const Form& other);
  Form(const std::string& name, const unsigned int& gradeToSign,
       const unsigned int& gradeToExecute);

  // Operator overloads
  Form& operator=(const Form& other);

  // Getters and Setters
  std::string getName() const;
  unsigned int getGradeRequiredToSign() const;
  unsigned int getGradeRequiredToExecute() const;
  bool isSigned() const;

  // Logic
  // change form to signed if bureucrate garde is high enough
  void beSigned(Bureaucrat& b);
};

// std::cout << overload
std::ostream& operator<<(std::ostream& out, const Form& f);

#endif
