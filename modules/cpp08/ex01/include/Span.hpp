#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>

class Span {
 private:
  unsigned int N;
  std::vector<int> _payload;

 public:
 private:

 public:
  Span();
  ~Span();
  Span(const Span& other);
  Span(unsigned int N);

  Span& operator=(const Span& other);

  class FullSpanException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class RangeTooSmallException : public std::exception {
   public:
    virtual const char* what(void) const throw();
  };

  unsigned int size() const;
  const std::vector<int> getPayload() const;
  void addNumber(const int n);
  int shortestSpan();
  int longestSpan();
  void addMultipleNumbers();
};

std::ostream& operator <<(std::ostream& out, const Span& span);
#endif  // SPAN_HPP
