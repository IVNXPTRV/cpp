#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T, typename F>
void iter(T *array, const size_t &len, F (*f)){
  if (array == NULL || f == NULL)
    return;
  for (size_t i = 0; i < len; i++) {
    f(array[i]);
  }
}

template <typename T>
void printItem(const T &item){
  std::cout << item << " ";
}

template <typename T>
void incByOne(T &item){
  item += 1;
}
#endif
