#include <iostream>
#include <cmath>
#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

    // MY TESTS
    Array<float> arrf;
    Array<float> arrf1(arrf);

    Array<double> arrd(42);
    Array<double> arrd1;

    std::cout << "arrd size: " << arrd.size() << std::endl;
    std::cout << "arrd1 size: " << arrd1.size() << std::endl;
    arrd1 = arrd;
    std::cout << "arrd1 size: " << arrd1.size() << std::endl;
    std::cout << "arrd1[0]: " << arrd1[0] << std::endl;
    arrd1[0] = 42.42;
    std::cout << "arrd1[0]: " << arrd1[0] << std::endl;
    return 0;
}
