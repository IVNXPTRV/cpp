#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <string>
#include <iostream>

typedef enum {
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

  // Operator overloads
  ScalarConverter& operator=(const ScalarConverter& other);
  // Logic

  // Exceptions

  // Public Methods
 public:
  // Constructors and Destructors

  // Getters and Setters

  // Logic
  static void convert(const std::string& str);
};

#endif
