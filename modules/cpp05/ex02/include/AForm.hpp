#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>

class Bureaucrat;
class AForm {
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
  virtual void beExecuted() const = 0; 

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
  class NotSignedException : public std::exception {
   public:
    virtual const char* what(void) const throw();
  };

  // Public Methods
 public:
  // Constructors and Destructors
  AForm();
  virtual ~AForm();
  AForm(const AForm& other);
  AForm(const std::string& name, const unsigned int& gradeToSign,
       const unsigned int& gradeToExecute);

  // Operator overloads
  AForm& operator=(const AForm& other);

  // Getters and Setters
  std::string getName() const;
  unsigned int getGradeRequiredToSign() const;
  unsigned int getGradeRequiredToExecute() const;
  bool isSigned() const;

  // Logic
  void beSigned(Bureaucrat& b);
  void execute(Bureaucrat const & executor) const;
  // change form to signed if bureucrate garde is high enough
};

// std::cout << overload
std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif
