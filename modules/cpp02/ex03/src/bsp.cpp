#include "Point.hpp"

bool inSegment(const Point p1, const Point p2, const Point p) {
  // If the line is vertical, check if the point 'p' is on the same vertical
  // line and if its y-coordinate is between the y-coordinates of p1 and p2.
  if (p1.getX() == p2.getX()) {
    return p.getX() == p1.getX() &&
           ((p.getY() >= p1.getY() && p.getY() <= p2.getY()) ||
            (p.getY() >= p2.getY() && p.getY() <= p1.getY()));
  }
  Fixed m((p1.getY() - p2.getY()) / (p1.getX() - p2.getX()));
  Fixed b(p1.getY() - m * p1.getX());

  return (p.getY() == m * p.getX() + b);
}

float abs(float x) { return (x < 0 ? -x : x); }

//! Using the Shoelace Formula to calculate the area of a triangle with any
//! orientation
float area(const Point p1, const Point p2, const Point p3) {
  Fixed first(p1.getX() * p2.getY() - p3.getX() * p2.getY());
  Fixed second(p3.getX() * p1.getY() - p1.getX() * p3.getY());
  Fixed third(p2.getX() * p3.getY() - p2.getX() * p1.getY());
  Fixed result(first + second + third);

  return (abs(result.toFloat()) / 2);
}

//! Dividing the triangle in 3 triangles, the sum of the inners should equal the
//! total
bool bsp(Point const a, Point const b, Point const c, Point const point) {
  //! If the point belongs to one of the sides of the triangle
  if (inSegment(a, b, point) || inSegment(b, c, point) ||
      inSegment(c, a, point))
    return (false);

  float areaABP = area(a, b, point);
  float areaBCP = area(b, c, point);
  float areaCAP = area(c, a, point);
  float areaABC = area(a, b, c);
  return abs(areaABC - (areaABP + areaBCP + areaCAP)) < 0.0001f;
}
