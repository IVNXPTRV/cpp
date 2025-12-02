#include "ShrubberyCreationForm.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

static const std::string defaultName = "Shrubbery Creation Form";
static const unsigned int defaultGradeRequiredToSign =
    ShrubberyCreationForm::gradeToSign;
static const unsigned int defaultGradeRequiredToExecute =
    ShrubberyCreationForm::gradeToExecute;
static const std::string defaultTarget = "Shrub Target";

static std::string const shrubberyTree1 =
    "\n"
    "                %%%,%%%%%%%\n"
    "                 ,'%% \\\\-*%%%%%%%\n"
    "           ;%%%%%*%   _%%%%\"\n"
    "            ,%%%       \\(_.*%%%%.\n"
    "            % *%%, ,%%%%*(    '\n"
    "          %^     ,*%%% )\\|,%%*%,_\n"
    "               *%    \\/ #).-\"*%%*\n"
    "                   _.) ,/ *%,\n"
    "           _________/)#(_____________\n\n";

static std::string const shrubberyTree2 =
    "\n"
    "           \\/ |    |/\n"
    "        \\/ / \\||/  /_/___/_\n"
    "         \\/   |/ \\/\n"
    "    _\\__\\_\\   |  /_____/_\n"
    "           \\  | /          /\n"
    "  __ _-----`  |{,-----------~\n"
    "            \\ }{\n"
    "             }{{\n"
    "             }}{\n"
    "             {{}\n"
    "       , -=-~{ .-^- _\n"
    "             `}\n"
    "              {\n\n";

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm(defaultName, defaultGradeRequiredToSign,
            defaultGradeRequiredToExecute),
      _target(defaultTarget) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other)
    : AForm(other), _target(defaultTarget) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm(defaultName, defaultGradeRequiredToSign,
            defaultGradeRequiredToExecute),
      _target(target) {}

void ShrubberyCreationForm::beExecuted() const {
  std::ofstream ofs;
  ofs.open((this->_target + "_shrubbery").c_str(), std::ofstream::out);
  if (ofs.fail())
    throw std::runtime_error("Could not open " + this->_target + "_shrubbery");
  if (std::rand() % 2)
    ofs << shrubberyTree1;
  else
    ofs << shrubberyTree2;
  std::cout << "A shrubbery has been planted at " << _target << "_shrubbery."
            << std::endl;
  ofs.close();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& other) {
  if (this == &other) return *this;
  this->_target = other._target;
  return *this;
}
