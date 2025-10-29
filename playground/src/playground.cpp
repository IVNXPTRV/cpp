
#include <ios>
#include <vector>
#include <iostream>
#include <stdlib.h>

class Animal{
    public:
    static int s_x;
  Animal(void);
  ~Animal(void);
    void say(void) const;
    int y;
   private:
        int x;
};

void Animal::say(void) const
{
  std::cout << "whroom";
  return;
}

Animal::Animal()
{
  std::cout << "hello";
}

Animal::~Animal()
{
  std::cout << "bye";
}

int Animal::s_x = 2;
int main(void) {
  // Animal x;
  std::cout << Animal::s_x;
// Try to access an element that does not exist (throws an error message)
  try{
  }
  catch (...)
    {
      std::cout << "helllll";
    }
  //   *   // struct itgr i; 
  //   std::string line = "world";
  // char str[10];
  // line.append("a");
  //   // std::cin >> line; 
  //   // std::cout << line;
  //   // std::cout << &i << std::endl;
  //   // std::cout << &(i.x) << std::endl;
  // std::getline(std::cin, line);
  //   std::cout << line + "H" + "E" + "L" << std::endl;
  //   std::cout << str << std::endl;
  return (EXIT_SUCCESS);
}
