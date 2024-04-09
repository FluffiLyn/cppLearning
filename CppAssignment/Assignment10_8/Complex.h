#ifndef COMPLEX_H
#define COMPLEX_H 
#include <iostream>

class Complex
{
public:
    explicit Complex(double = 0.0, double = 0.0);
    Complex operator+(const Complex&) const;
    Complex operator-(const Complex&) const;
    Complex operator*(const Complex&) const;
    bool operator==(const Complex&) const;
    bool operator!=(const Complex&) const;

    friend std::istream & operator>>(std::istream&, Complex&);
    friend std::ostream & operator<<(std::ostream&, Complex&);

    double getReal() const;
    double getImaginary() const;

private:
    double real;
    double imaginary;
};

#endif 