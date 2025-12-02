#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Form;
class Bureaucrat {
  // Private Attributes
 private:
  const std::string _name;
  unsigned int _grade;

  // Public Attributes
 public:
  static int const highestGrade = 1;
  static int const lowestGrade = 150;

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

  // Public Methods
 public:
  // Constructors and Destructors
  Bureaucrat();
  ~Bureaucrat();
  Bureaucrat(const Bureaucrat& other);
  Bureaucrat(std::string name, unsigned int grade);

  // Operator overloads
  Bureaucrat& operator=(const Bureaucrat& other);

  // Getters and Setters
  std::string getName() const;
  unsigned int getGrade() const;

  // Logic
  void incrementGrade();
  void decrementGrade();
  void signForm(Form &f);
};

// std::cout << overload
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif
