#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

#include "Data.hpp"

class Serializer {
  // Private Attributes
 private:
  // Public Attributes
 public:
  // Private Methods
 private:
  Serializer();

  ~Serializer();
  Serializer(const Serializer& other);

  // Operator overloads
  Serializer& operator=(const Serializer& other);
  // Logic

  // Exceptions

  // Public Methods
 public:
  // Constructors and Destructors

  // Getters and Setters

  // Logic
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
};

#endif
