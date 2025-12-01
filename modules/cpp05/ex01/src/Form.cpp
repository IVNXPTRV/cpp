#include "Form.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

static const std::string defaultName = "Foo";
static const unsigned int defaultGradeRequiredToSign = Bureaucrat::lowestGrade;
static const unsigned int defaultGradeRequiredToExecute =
    Bureaucrat::lowestGrade;

// Private Methods
// Logic
void Form::confirmValidGrade(unsigned int grade) {
  if (grade < Bureaucrat::highestGrade) throw(Form::GradeTooHighException());
  if (grade > Bureaucrat::lowestGrade) throw(Form::GradeTooLowException());
}

const char* Form::GradeTooHighException::what() const throw() {
  return ("Grade is too high for this form");
}

const char* Form::GradeTooLowException::what() const throw() {
  return ("Grade is too low for this form");
}

const char* Form::AlreadySignedException::what() const throw() {
  return ("Form is already signed");
}
// Public Methods
// Constructors and Destructors
Form::Form()
    : _name(defaultName),
      _gradeRequiredToSign(defaultGradeRequiredToSign),
      _gradeRequiredToExecute(defaultGradeRequiredToExecute),
      _isSigned(false) {}
Form::~Form() {}
Form::Form(const Form& other)
    : _name(other._name),
      _gradeRequiredToSign(other._gradeRequiredToSign),
      _gradeRequiredToExecute(other._gradeRequiredToExecute),
      _isSigned(other._isSigned) {}

Form::Form(const std::string& name, const unsigned int& gradeToSign,
           const unsigned int& gradeToExecute)
    : _name(name),
      _gradeRequiredToSign(gradeToSign),
      _gradeRequiredToExecute(gradeToExecute),
      _isSigned(false) {
  confirmValidGrade(_gradeRequiredToSign);
  confirmValidGrade(_gradeRequiredToExecute);
}

// Operator overloads
Form& Form::operator=(const Form& other) {
  if (this == &other) return *this;
  this->_isSigned = other._isSigned;
  return *this;
}
// Getters and Setters
std::string Form::getName() const { return this->_name; }
unsigned int Form::getGradeRequiredToSign() const {
  return this->_gradeRequiredToSign;
}
unsigned int Form::getGradeRequiredToExecute() const {
  return this->_gradeRequiredToExecute;
}
bool Form::isSigned() const { return this->_isSigned; }

// Logic
void Form::beSigned(Bureaucrat& b) {
  if (this->_gradeRequiredToSign < b.getGrade())
    throw(Form::GradeTooLowException());
  if (this->_isSigned == true)
    throw(Form::AlreadySignedException());
  this->_isSigned = true;
  std::cout << b.getName() << " form signed by bureaucrat " << this->_name << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Form& b) {
  out << b.getName() << "form is " << (b.isSigned() ? "signed" : "unsigned")
      << std::endl;
  out << "Required grade to sign: " << b.getGradeRequiredToSign() << std::endl;
  out << "Required grade to execute: " << b.getGradeRequiredToExecute()
      << std::endl;
  return out << std::endl;
}
