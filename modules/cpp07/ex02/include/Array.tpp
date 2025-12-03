#include "Array.hpp"

template <typename T>
Array<T>::Array() : _n(0) {
  this->_items = new T[this->_n]();
}

template <typename T>
Array<T>::Array(const Array<T> &other) : _n(other._n) {
  this->_items = NULL;
  *this = other;
}

template <typename T>
Array<T>::Array(const unsigned int &n) : _n(n) {
  this->_items = new T[this->_n]();
}

template <typename T>
Array<T>::~Array() {
  delete[] this->_items;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other) {
  if (this == &other) return *this;
  delete[] this->_items;
  this->_n = other._n;
  this->_items = new T[this->_n]();
  for (unsigned int i = 0; i < this->_n; i++) {
    this->_items[i] = other._items[i];
  }
  return *this;
}

template <typename T>
T& Array<T>::operator[](const unsigned int &index) {
  if (index > (this->_n - 1)) throw Array<T>::IndexOutOfBoundException();
  return this->_items[index];
}

template <typename T>
unsigned int Array<T>::size() const {
  return this->_n;
}

template <typename T>
const char *Array<T>::IndexOutOfBoundException::what() const throw() {
  return "Index is out of bound";
}
