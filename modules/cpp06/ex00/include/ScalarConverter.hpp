#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
  // Private Attributes
 private:

  // Public Attributes
 public:

  // Private Methods
 private:
  // Logic

  // Exceptions

  // Public Methods
 public:
  // Constructors and Destructors
  ScalarConverter();
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter& other);
  ScalarConverter(std::string name, unsigned int grade);

  // Operator overloads
  ScalarConverter& operator=(const ScalarConverter& other);

  // Getters and Setters

  // Logic
  static void convert(const std::string &str);
};

// std::cout << overload
std::ostream& operator<<(std::ostream& out, const ScalarConverter& b);

#endif
