#include "Serializer.hpp"

#include <cctype>

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& copy) { *this = copy; }

Serializer::~Serializer() {}

Serializer& Serializer::operator=(const Serializer& other) {
  if (this == &other) return (*this);
  return (*this);
}

uintptr_t Serializer::serialize(Data* ptr) {
  // if (sizeof(Data) != sizeof(uintptr_t))
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data*>(raw);
}
