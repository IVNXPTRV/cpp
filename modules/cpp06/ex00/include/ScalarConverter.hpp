#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <cstdlib>
#include <limits>
#include <iostream>
#include <cctype>
#include <cmath>
#include <cerrno>

# define DIGITS "0123456789"

typedef enum
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
} t_type;

class ScalarConverter {
  // Private Attributes
 private:

  // Public Attributes
 public:

  // Private Methods
 private:
  ScalarConverter();
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter& other);
  ScalarConverter(std::string name, unsigned int grade);

  // Operator overloads
  ScalarConverter& operator=(const ScalarConverter& other);
  // Logic

  // Exceptions

  // Public Methods
 public:
  // Constructors and Destructors

  // Getters and Setters

  // Logic
  static void convert(const std::string &str);
};

// std::cout << overload
std::ostream& operator<<(std::ostream& out, const ScalarConverter& b);

#endif
