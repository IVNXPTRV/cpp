#include <cstdlib>

#include "Serializer.hpp"

int main() {
  Data data = {"Foo", 20};
  uintptr_t payload = 0;
  Data *copy = NULL;

  payload = Serializer::serialize(&data);
  std::cout << "Data address: " << &data << std::endl;
  std::cout << "Payload content: " << std::hex << payload << std::dec
            << std::endl;

  copy = Serializer::deserialize(payload);
  std::cout << "Data copy address: " << copy << std::endl;
  std::cout << "data->name: " << data.name << std::endl;
  std::cout << "copy->name: " << copy->name << std::endl;
  std::cout << "data->age: " << data.age << std::endl;
  std::cout << "copy->age: " << copy->age << std::endl;

  return EXIT_SUCCESS;
}
