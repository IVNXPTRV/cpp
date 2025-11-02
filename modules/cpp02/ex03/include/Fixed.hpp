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

  bool operator>(const Fixed& other) const;
  bool operator<(const Fixed& other) const;
  bool operator>=(const Fixed& other) const;
  bool operator<=(const Fixed& other) const;
  bool operator==(const Fixed& other) const;
  bool operator!=(const Fixed& other) const;

  Fixed operator+(const Fixed& other);
  Fixed operator-(const Fixed& other);
  Fixed operator*(const Fixed& other);
  Fixed operator/(const Fixed& other);

  Fixed operator++(void);  // prefix
  Fixed operator--(void);  // prefix
  Fixed operator++(
      int dummy);  // postfix dummy parameter, which is always passed the value
                   // 0 by the compiler, serves only to distinguish the function
                   // signature from the prefix version.
  Fixed operator--(int dummy);  // postfix

  static Fixed& min(Fixed& f1, Fixed& f2);
  static Fixed& max(Fixed& f1, Fixed& f2);

  static const Fixed& min(const Fixed& f1, const Fixed& f2);
  static const Fixed& max(const Fixed& f1, const Fixed& f2);

 private:
  int _raw;
  static const int _fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& number);

#endif
