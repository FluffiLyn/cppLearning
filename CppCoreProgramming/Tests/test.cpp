// basics/max1.cpp
#include "max1.hpp"
#include <iostream>

int main()
{
    int i = 42;
    std::cout << "max(7,i): " <<::max(7,i) << std::endl;

    double f1 = 3.4, f2 = -6.7;
    std::cout << "max(f1,f2): " << ::max(f1, f2) << std::endl;

    return 0;
}
