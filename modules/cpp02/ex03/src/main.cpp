#include <cstdlib>
#include <iostream>
#include <sstream>

#include "Point.hpp"

bool isValidNum(std::string str, int &num) {
  std::stringstream ss(str);
  ss >> num;
  return (!ss.fail() && ss.eof());
}

int stoi(std::string str) {
  int num;
  std::stringstream ss(str);
  ss >> num;
  return (num);
}

bool isValidInput(int argc, char *argv[]) {
  int num;

  if (argc != 9) {
    std::cout << "Usage: ./bsp a.x a.y b.x b.y c.x c.y p.x p.y " << std::endl;
    std::cout << "Where a, b, c are vertices of a triangle and p is a point"
              << std::endl;
    return false;
  }
  for (int i = 1; i < 9; i++) {
    if (!isValidNum(argv[i], num)) {
      std::cout << "Bad input" << std::endl;
      return false;
    }
    if (num > 8388607) {
      std::cout << "num can't be more than 8388697" << std::endl;
      return false;
    }
  }
  return true;
}

bool bsp(Point const a, Point const b, Point const c, Point const p);

int main(int argc, char *argv[]) {
  if (!isValidInput(argc, argv)) return EXIT_FAILURE;
  if (bsp(Point(stoi(argv[1]), stoi(argv[2])),
          Point(stoi(argv[3]), stoi(argv[4])),
          Point(stoi(argv[5]), stoi(argv[6])),
          Point(stoi(argv[7]), stoi(argv[8]))))
    std::cout << "(" << argv[7] << "," << argv[8]
              << ") is inside of the triangle" << std::endl;
  else
    std::cout << "(" << argv[7] << "," << argv[8]
              << ") is outside of the triangle" << std::endl;
  return EXIT_SUCCESS;
}
