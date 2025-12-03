#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array {
 private:
  T *_items;
  unsigned int _n;

 public:
  Array();
  Array(const Array<T> &other);
  Array(const unsigned int &n);
  ~Array();

  Array<T> &operator=(const Array<T> &other);
  T &operator[](const unsigned int &index);

  unsigned int size() const;

  class IndexOutOfBoundException : public std::exception {
   public:
    virtual const char *what() const throw();
  };
};

#include "Array.tpp"
#endif
