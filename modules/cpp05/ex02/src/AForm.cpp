#include "AForm.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

static const std::string defaultName = "Foo";
static const unsigned int defaultGradeRequiredToSign = Bureaucrat::lowestGrade;
static const unsigned int defaultGradeRequiredToExecute =
    Bureaucrat::lowestGrade;

// Private Methods
// Logic
void AForm::confirmValidGrade(unsigned int grade) {
  if (grade < Bureaucrat::highestGrade) throw(AForm::GradeTooHighException());
  if (grade > Bureaucrat::lowestGrade) throw(AForm::GradeTooLowException());
}

const char* AForm::GradeTooHighException::what() const throw() {
  return ("Grade is too high for this form");
}

const char* AForm::GradeTooLowException::what() const throw() {
  return ("Grade is too low for this form");
}

const char* AForm::AlreadySignedException::what() const throw() {
  return ("Form is already signed");
}

const char* AForm::NotSignedException::what() const throw() {
  return ("Form has not been signed");
}
// Public Methods
// Constructors and Destructors
AForm::AForm()
    : _name(defaultName),
      _gradeRequiredToSign(defaultGradeRequiredToSign),
      _gradeRequiredToExecute(defaultGradeRequiredToExecute),
      _isSigned(false) {}
AForm::~AForm() {}
AForm::AForm(const AForm& other)
    : _name(other._name),
      _gradeRequiredToSign(other._gradeRequiredToSign),
      _gradeRequiredToExecute(other._gradeRequiredToExecute),
      _isSigned(other._isSigned) {}

AForm::AForm(const std::string& name, const unsigned int& gradeToSign,
           const unsigned int& gradeToExecute)
    : _name(name),
      _gradeRequiredToSign(gradeToSign),
      _gradeRequiredToExecute(gradeToExecute),
      _isSigned(false) {
  confirmValidGrade(_gradeRequiredToSign);
  confirmValidGrade(_gradeRequiredToExecute);
}

// Operator overloads
AForm& AForm::operator=(const AForm& other) {
  if (this == &other) return *this;
  this->_isSigned = other._isSigned;
  return *this;
}
// Getters and Setters
std::string AForm::getName() const { return this->_name; }
unsigned int AForm::getGradeRequiredToSign() const {
  return this->_gradeRequiredToSign;
}
unsigned int AForm::getGradeRequiredToExecute() const {
  return this->_gradeRequiredToExecute;
}
bool AForm::isSigned() const { return this->_isSigned; }

// Logic
void AForm::beSigned(Bureaucrat& b) {
  if (this->_gradeRequiredToSign < b.getGrade())
    throw(AForm::GradeTooLowException());
  if (this->_isSigned == true) throw(AForm::AlreadySignedException());
  this->_isSigned = true;
}

void  AForm::execute(Bureaucrat const & executor) const {
  if (this->_gradeRequiredToExecute < executor.getGrade())
    throw AForm::GradeTooLowException();
  if (this->_isSigned == false)
    throw AForm::NotSignedException();
  this->beExecuted();
}

std::ostream& operator<<(std::ostream& out, const AForm& b) {
  out << b.getName() << " is " << (b.isSigned() ? "signed" : "unsigned")
      << std::endl;
  out << "Required grade to sign: " << b.getGradeRequiredToSign() << std::endl;
  out << "Required grade to execute: " << b.getGradeRequiredToExecute();
  return out;
}
