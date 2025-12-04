#include <iostream>

#include "Span.hpp"

int main() {
  // MY TESTS
  {
    Span sp = Span(10001);
    sp.addMultipleNumbers();
    std::cout << sp << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << std::endl;
  }
  {
    Span sp = Span(5);
    sp.addNumber(0);
    sp.addNumber(1);
    sp.addNumber(2);
    // sp.addNumber(3);
    // sp.addNumber(4);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << std::endl;
  }
  {
    Span sp = Span(5);
    sp.addNumber(0);
    try {
      std::cout << sp.shortestSpan() << std::endl;
    } catch (const std::exception &e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
  }
  {
    Span sp = Span(1);
    sp.addNumber(0);
    try {
      sp.addNumber(1);
    } catch (const std::exception &e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
  }
  // SUBJECT TEST
  {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << std::endl;
  }
  return 0;
}
