#include "easyfind.hpp"
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::const_iterator easyfind(const T &c, const int i){
  typename T::const_iterator it;
  it = std::find(c.begin(), c.end(), i);
  if (it == c.end())
    throw std::out_of_range("Item not found in container.");
  return it;
}
