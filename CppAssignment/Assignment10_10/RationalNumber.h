#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H

#include <iostream>
using namespace std;

class RationalNumber 
{
public:

    RationalNumber(int = 0, int = 1);


    RationalNumber operator+(const RationalNumber&) const;
    RationalNumber operator-(const RationalNumber&) const;
    RationalNumber operator*(const RationalNumber&) const;
    RationalNumber operator/(const RationalNumber&) const;


    bool operator==(const RationalNumber&) const;
    bool operator!=(const RationalNumber&) const;
    bool operator<(const RationalNumber&) const;
    bool operator<=(const RationalNumber&) const;
    bool operator>(const RationalNumber&) const;
    bool operator>=(const RationalNumber&) const;

    friend istream& operator>>(istream&, RationalNumber&);
    friend ostream& operator<<(ostream&, const RationalNumber&);
private:
    int numerator;
    int denominator; 
};




#endif