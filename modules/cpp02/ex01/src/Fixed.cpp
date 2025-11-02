#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : _raw(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& num) {
  std::cout << "Copy constructor called" << std::endl;
  *this = num;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(const int num) : _raw(num << Fixed::_fractionalBits) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num)
    : _raw(static_cast<int>(
          roundf(num * (1.0f * (1 << Fixed::_fractionalBits))))) {
  std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const {
  return (float)this->_raw / (float)(1 << Fixed::_fractionalBits);
}

int Fixed::toInt(void) const { return this->_raw >> Fixed::_fractionalBits; }

Fixed& Fixed::operator=(const Fixed& other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this == &other) return (*this);
  this->_raw = other._raw;
  return (*this);
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return (this->_raw);
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->_raw = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& number) {
  return os << number.toFloat();
}
