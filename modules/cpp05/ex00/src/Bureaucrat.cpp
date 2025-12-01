#include "Bureaucrat.hpp"

#include <iostream>

static const std::string defaultName = "Bob";
static const unsigned int defaultGrade = Bureaucrat::lowestGrade;

// Private Methods
// Logic
void Bureaucrat::confirmValidGrade(unsigned int grade) {
  if (grade < Bureaucrat::highestGrade)
    throw(Bureaucrat::GradeTooHighException());
  if (grade > Bureaucrat::lowestGrade)
    throw(Bureaucrat::GradeTooLowException());
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade is too low.");
}

// Public Methods
// Constructors and Destructors
Bureaucrat::Bureaucrat() : _name(defaultName), _grade(defaultGrade) {}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade) {}
Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
    : _name(name), _grade(grade) {
  // throws exception if invalid
  confirmValidGrade(_grade);
}

// Operator overloads
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  if (this == &other) return *this;
  this->_grade = other._grade;
  return *this;
}
// Getters and Setters
std::string Bureaucrat::getName() const { return this->_name; }
unsigned int Bureaucrat::getGrade() const { return this->_grade; }

// Logic
void Bureaucrat::incrementGrade() {
  this->_grade -= 1;
  confirmValidGrade(this->_grade);
  std::cout << this->_name << " was promoted to grade " << this->_grade << "!"
            << std::endl;
}
void Bureaucrat::decrementGrade() {
  this->_grade += 1;
  confirmValidGrade(this->_grade);
  std::cout << this->_name << " was demoted to grade " << this->_grade << "!"
            << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b){
  return out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
}
