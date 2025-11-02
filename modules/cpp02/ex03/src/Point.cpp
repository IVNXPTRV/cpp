#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const Point& other) : _x(other.getX()), _y(other.getY()) {}

Point& Point::operator=(const Point& other) {
  if (this == &other) return *this;
  (Fixed) this->_x = other.getX();
  (Fixed) this->_y = other.getY();
  return (*this);
}

Point::~Point() {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

bool Point::operator==(const Point& other) {
  return (this->getX() == other.getX()) && (this->getY() == other.getY());
}

Fixed Point::getX() const { return (this->_x); }

Fixed Point::getY() const { return (this->_y); }
