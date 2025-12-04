#include "Span.hpp"

#include <algorithm>
#include <ctime>
#include <iostream>
#include <limits>
#include <vector>

Span::Span() : N(0) {};
Span::~Span() {};
Span::Span(const Span& other) : N(other.N), _payload(other._payload) {}
Span::Span(unsigned int N) : N(N) {}
Span& Span::operator=(const Span& other) {
  if (this == &other) return *this;
  this->N = other.N;
  this->_payload = other._payload;
  return *this;
}

void Span::addNumber(const int n) {
  if (this->_payload.size() == this->N) throw FullSpanException();
  this->_payload.push_back(n);
  std::sort(this->_payload.begin(), this->_payload.end());
}

int Span::shortestSpan() {
  if (this->_payload.size() < 2) throw RangeTooSmallException();
  int min = std::numeric_limits<int>::max();
  std::sort(this->_payload.begin(), this->_payload.end());
  std::vector<int>::const_iterator curr;
  for (curr = this->_payload.begin() + 1; curr != this->_payload.end();
       curr++) {
    int diff = *curr - *(curr - 1);
    if (diff < min) min = diff;
  }
  return min;
}

int Span::longestSpan() {
  if (this->_payload.size() < 2) throw RangeTooSmallException();
  return *std::max_element(this->_payload.begin(), this->_payload.end()) -
         *std::min_element(this->_payload.begin(), this->_payload.end());
}

static int genRandomNum() { return std::rand() % 100; }

void Span::addMultipleNumbers() {
  this->_payload.resize(this->N);
  std::generate(this->_payload.begin(), this->_payload.end(), &genRandomNum);
  std::sort(this->_payload.begin(), this->_payload.end());
}

const char* Span::FullSpanException::what() const throw() {
  return "Payload of Span is full";
}

const char* Span::RangeTooSmallException::what() const throw() {
  return "Payload of Span consists of less then 2 items";
}

unsigned int Span::size() const { return this->N; }

const std::vector<int>& Span::getPayload() const { return this->_payload; }

std::ostream& operator<<(std::ostream& out, const Span& span) {
  for (unsigned int i = 0; i < span.size(); i++) out << span.getPayload()[i] << " ";
  out << std::endl;
  return out;
}
