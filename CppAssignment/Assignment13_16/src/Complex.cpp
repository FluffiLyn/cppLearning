#include "Complex.h"
#include <iostream>
#include <istream>
using namespace std;

ostream& operator<<(ostream& output, const Complex& c) 
{
    if (!std::cin.fail())
    {
        output << c.real;
        if (c.imaginary >= 0)
            output << " + " << c.imaginary << "i";
        else
            output << " - " << -c.imaginary << "i";
    }
    else
        output << "Invalid Data" << endl;

    return output;
}

istream& operator>>(istream& input, Complex& c) 
{
    int realPart, imaginaryPart;
    char sign;

    // 读取实部
    if (input >> realPart) 
    {
        // 检查下一个字符是否为空格
        if (input.get() == ' ') 
        {
            // 读取符号
            if (input >> sign && (sign == '+' || sign == '-')) 
            {
                // 读取虚部
                if (input >> imaginaryPart) 
                {
                    // 确保虚部后面紧接着是 'i'
                    if (input.get() == 'i') 
                    {
                        c.real = realPart;
                        c.imaginary = (sign == '+') ? imaginaryPart : -imaginaryPart;
                    } 
                    else 
                        input.setstate(ios::failbit);
                } 
                else 
                    input.setstate(ios::failbit);
            } 
            else 
                input.setstate(ios::failbit);
        } 
        else 
            input.setstate(ios::failbit);
    } 
    else 
        input.setstate(ios::failbit);

    return input;
}
