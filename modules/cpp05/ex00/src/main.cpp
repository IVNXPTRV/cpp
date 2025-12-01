#include <cstdlib>
#include <iostream>

#include "Bureaucrat.hpp"

void test_default_constructor(std::string name, unsigned int grade) {
  (void)name;
  (void)grade;
  std::cout << "Default constructor test" << std::endl;
  Bureaucrat b1;
  std::cout << b1 << std::endl;
}

void test_paramed_constructor(std::string name, unsigned int grade) {
  std::cout << "Paramed constructor test" << std::endl;
  Bureaucrat b1(name, grade);
  std::cout << b1 << std::endl;
}

void test_inc_grade(std::string name, unsigned int grade) {
  std::cout << "Grade increment test" << std::endl;
  Bureaucrat b1(name, grade);
  std::cout << b1 << std::endl;
  b1.incrementGrade();
  std::cout << b1 << std::endl;
}

void test_dic_grade(std::string name, unsigned int grade) {
  std::cout << "Grade dincrement test" << std::endl;
  Bureaucrat b1(name, grade);
  std::cout << b1 << std::endl;
  b1.dicrementGrade();
  std::cout << b1 << std::endl;
}
void test(std::string name, unsigned int grade, void (*func)(std::string, unsigned int)){
  try {
    func(name, grade);
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
  std::cout << std::endl;
}

int main() {
  test("", 1, test_default_constructor);

  test("Foo", 1, test_paramed_constructor);
  test("Bar", 150, test_paramed_constructor);
  test("Baz", 100, test_paramed_constructor);
  test("Qux", 200, test_paramed_constructor);
  test("Corge", 10, test_paramed_constructor);
  
  
  test("Foo", 10, test_inc_grade);
  test("Bar", 22, test_dic_grade);
  test("Baz", 1, test_inc_grade);
  test("Qux", 44, test_inc_grade);
  test("Corge", 150, test_dic_grade);
  
  return EXIT_SUCCESS;
}
