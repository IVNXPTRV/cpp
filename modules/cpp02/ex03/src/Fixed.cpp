#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : _raw(0) {}

Fixed::Fixed(const Fixed& num) { *this = num; }

Fixed::~Fixed() {}

Fixed::Fixed(const int num) : _raw(num << Fixed::_fractionalBits) {}

Fixed::Fixed(const float num)
    : _raw(static_cast<int>(
          roundf(num * (1.0f * (1 << Fixed::_fractionalBits))))) {}

float Fixed::toFloat(void) const {
  return (float)this->_raw / (float)(1 << Fixed::_fractionalBits);
}

int Fixed::toInt(void) const { return this->_raw >> Fixed::_fractionalBits; }

Fixed& Fixed::operator=(const Fixed& other) {
  if (this == &other) return (*this);
  this->_raw = other._raw;
  return (*this);
}

int Fixed::getRawBits(void) const { return (this->_raw); }

void Fixed::setRawBits(int const raw) { this->_raw = raw; }

std::ostream& operator<<(std::ostream& os, const Fixed& number) {
  return os << number.toFloat();
}

bool Fixed::operator>(const Fixed& other) const {
  return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const {
  return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const {
  return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const {
  return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const {
  return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const {
  return (this->getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed& other) {
  return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) {
  return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) {
  return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) {
  return Fixed(this->toFloat() / other.toFloat());
}

Fixed Fixed::operator++(void) {
  this->_raw++;
  return (*this);
}

Fixed Fixed::operator--(void) {
  this->_raw--;
  return (*this);
}

// clone because we return value before incerement
Fixed Fixed::operator++(int dummy) {
  Fixed clone(*this);

  (void)dummy;
  ++(*this);
  return (clone);
}

Fixed Fixed::operator--(int dummy) {
  Fixed clone(*this);

  (void)dummy;
  --(*this);
  return (clone);
}

Fixed& Fixed ::min(Fixed& f1, Fixed& f2) { return (f1 < f2 ? f1 : f2); }

const Fixed& Fixed ::min(const Fixed& f1, const Fixed& f2) {
  return (f1 < f2 ? f1 : f2);
}

Fixed& Fixed ::max(Fixed& f1, Fixed& f2) { return (f1 > f2 ? f1 : f2); }

const Fixed& Fixed ::max(const Fixed& f1, const Fixed& f2) {
  return (f1 > f2 ? f1 : f2);
}
