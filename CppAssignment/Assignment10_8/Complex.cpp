#include "Complex.h"
using namespace std;

Complex::Complex(double realPart, double imaginaryPart)
    : real(realPart),
      imaginary(imaginaryPart)
{    
}

Complex Complex::operator+(const Complex &operand2) const
{
    return Complex(real + operand2.real, imaginary + operand2.imaginary);
}

Complex Complex::operator-(const Complex &operand2) const
{
    return Complex(real - operand2.real, imaginary - operand2.imaginary);
}

// (a+bi)(c+di)=(ac-bd)+(bc+ad)i
Complex Complex::operator*(const Complex &operand2) const
{
    return Complex(real * operand2.real - imaginary * operand2.imaginary, real * operand2.imaginary + imaginary * operand2.real);
}

bool Complex::operator==(const Complex &operand2) const
{
    if (real == operand2.real && imaginary == operand2.imaginary) 
        return true;
    else 
        return false;
    
}

bool Complex::operator!=(const Complex &operand2) const
{
    return !(*this == operand2);
}

ostream & operator<<(ostream& cout, Complex &c) 
{
    cout << c.real;
    
    if (c.imaginary < 0) 
    {
        cout << c.imaginary << "i";
    } 
    else {
        cout << "+" << c.imaginary << "i";
    }

    return cout;
}

istream & operator>>(istream &cin, Complex &c) 
{
    cin >> c.real >> c.imaginary;
    return cin;
}

double Complex::getReal() const
{
    return real;
}

double Complex::getImaginary() const
{
    return imaginary;
}