
#include <stdlib.h>

#include <ctime>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

int main(void) {
  std::time_t time;
  std::tm *timemark;

  time = std::time(NULL);
  timemark = std::localtime(&time);
  std::cout << "[" << timemark->tm_year + 1900;
  std::cout << std::setfill('0') << std::setw(2) << timemark->tm_mon + 1;
  std::cout << std::setfill('0') << std::setw(2) << timemark->tm_mday << "_";
  std::cout << std::setfill('0') << std::setw(2) << timemark->tm_hour;
  std::cout << std::setfill('0') << std::setw(2) << timemark->tm_min;
  std::cout << std::setfill('0') << std::setw(2) << timemark->tm_sec << "] ";
  return (EXIT_SUCCESS);
}
