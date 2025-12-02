#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) { *this = copy; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
  if (this == &other) return (*this);
  return (*this);
}
