#include "ScalarConverter.hpp"

#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) { *this = copy; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
  if (this == &other) return (*this);
  return (*this);
}

// bool isChar(const std::string &str){
//   return str.size() == 1 && !std::isdigit(str[0] && std::isprint(str[0]));
// }

// bool isInt(const std::string &str){

// }

// void ScalarConverter::convert(const std::string &str){
//  if (isChar(str))
//     convertPayload(str, str[0]);
//   else if (isInt(str))
//     convertPayload(str, std::atoi(str.c_str()));
//   else if (isFloat(str))
//     convertPayload(str, std::strtof(str.c_str(), NULL));
//   else if (isDouble(str))
//     convertPayload(str, std::strtod(str.c_str(), NULL));
//   else if (isPseudo(str))
//     convertPayload(str);
//   else
//     std::cout << str << " <-- wrong input" << std::endl;

// }

static bool isOverflow(const double& payload, t_type type) {
  switch (type) {
    case DOUBLE:
      return (errno == ERANGE);
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

static bool isValidChar(char c){
  return (std::isprint(c));
}

static void convertChar(const double& payload) {
  if (isOverflow(payload, CHAR)){
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
  // just check for char if f
  if (str == "-inff" || str == "+inff" || str == "nanf") return false;
  // if () printable character inout is ok
  if (*endptr != '\0' && str.size() > 0) return true;
  return false;
}

static bool isPseudo(double& payload) { return !std::isfinite(payload); }

void ScalarConverter::convert(const std::string& str) {
  char* endptr = NULL;
  double payload = std::strtod(str.c_str(), &endptr);

  if (isBadInput(endptr, str)) {
    std::cout << "Bad input --> " << str << std::endl;
    return;
  }

  if (isPseudo(payload) && (errno != ERANGE)) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << static_cast<float>(payload) << "f" << std::endl;
    std::cout << "double: " << payload << std::endl;
    return;
  }
  convertChar(payload);
}
