#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
 public:
  Point();
  Point(const Point& other);
  Point& operator=(const Point& other);
  ~Point();

  Point(const float x, const float y);

  bool operator==(const Point& other);
  Fixed getX() const;
  Fixed getY() const;

 private:
  const Fixed _x;
  const Fixed _y;
};

#endif
