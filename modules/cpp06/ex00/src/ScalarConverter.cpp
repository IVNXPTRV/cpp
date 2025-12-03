#include "ScalarConverter.hpp"

#include <cctype>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) { *this = copy; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
  if (this == &other) return (*this);
  return (*this);
}

static bool isOverflow(const double& payload, t_type type) {
  switch (type) {
    case DOUBLE: {
      bool overflow = errno;
      errno = 0;
      return (overflow);
    }
    case FLOAT:
      return (payload < -std::numeric_limits<float>::max() ||
              payload > std::numeric_limits<float>::max());
    case INT:
      return (payload < std::numeric_limits<int>::min() ||
              payload > std::numeric_limits<int>::max());
    case CHAR:
      return (payload < std::numeric_limits<char>::min() ||
              payload > std::numeric_limits<char>::max());
  }
}

static void convertDouble(const double& payload) {
  if (isOverflow(payload, DOUBLE)) {
    std::cout << "double: overflow" << std::endl;
    return;
  }
  std::string frc = ".0";
  if (payload != trunc(payload)) frc = "";
  std::cout << "double: " << payload << frc << std::endl;
}

static void convertFloat(const double& payload) {
  if (isOverflow(payload, FLOAT)) {
    std::cout << "float: overflow" << std::endl;
    return;
  }
  float f = static_cast<float>(payload);
  std::string frc = ".0";
  if (f != trunc(f)) frc = "";
  std::cout << "float: " << f << frc << "f" << std::endl;
}

static void convertInt(const double& payload) {
  if (isOverflow(payload, INT)) {
    std::cout << "int: overflow" << std::endl;
    return;
  }
  std::cout << "int: " << static_cast<int>(payload) << std::endl;
}

static bool isValidChar(char c) { return (std::isprint(c)); }

static void convertChar(const double& payload) {
  if (isOverflow(payload, CHAR)) {
    std::cout << "char: overflow" << std::endl;
    return;
  }
  char c = static_cast<char>(payload);
  if (isValidChar(c))
    std::cout << "char: " << c << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;
}

static bool isBadInput(char* endptr, const std::string& str) {
  if (std::isprint(*endptr) && *(endptr + 1) == '\0' && str.size() == 1)
    return false;
  if (*endptr == 'f' && *(endptr + 1) == '\0' && str.size() > 1) return false;
  if (*endptr != '\0' && str.size() > 0) return true;
  return false;
}

static double getPayload(const std::string& str, char** endptr) {
  double payload = std::strtod(str.c_str(), endptr);
  if (payload == 0.0 && str.size() == 1 && str[0] != '0') payload = str[0];
  return payload;
}

static bool isPseudo(double& payload) {
  return !std::isfinite(payload) && (errno != ERANGE);
}

void ScalarConverter::convert(const std::string& str) {
  char* endptr = NULL;
  double payload = getPayload(str, &endptr);

  if (isBadInput(endptr, str)) {
    std::cout << "Bad input --> " << str << std::endl;
    return;
  }

  if (isPseudo(payload)) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << static_cast<float>(payload) << "f" << std::endl;
    std::cout << "double: " << payload << std::endl;
    return;
  }
  convertChar(payload);
  convertInt(payload);
  convertFloat(payload);
  convertDouble(payload);
}
