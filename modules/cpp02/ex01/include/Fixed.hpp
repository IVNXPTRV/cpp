#ifndef FIXED_HPP
#define FIXED_HPP
#include <ostream>

class Fixed {
 public:
  Fixed();
  Fixed(const Fixed& other);
  Fixed& operator=(const Fixed& other);
  ~Fixed();

  Fixed(const int num);
  Fixed(const float num);

  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;

 private:
  int _raw;
  static const int _fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& number);

#endif
