#include "RationalNumber.h"

int gcd_(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd_(b, a % b);
}

int lcm_(int a, int b)
{
    return (a * b) / gcd_(a, b);
}


RationalNumber::RationalNumber(int nume, int deno) :
    numerator(nume), denominator(deno > 0? deno : -deno)
    {
        if (denominator == 0) 
        {
            throw invalid_argument("Denominator cannot be zero.");
        }
        
        int gcd = gcd_(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }


RationalNumber RationalNumber::operator+(const RationalNumber& other) const 
{

}

RationalNumber RationalNumber::operator-(const RationalNumber& other) const 
{

}

RationalNumber RationalNumber::operator*(const RationalNumber& other) const 
{

}

RationalNumber RationalNumber::operator/(const RationalNumber& other) const 
{

}

// Relational and equality operator overloads
bool RationalNumber::operator==(const RationalNumber& other) const 
{

}

bool RationalNumber::operator!=(const RationalNumber& other) const 
{
    return !(*this == other);
}

bool RationalNumber::operator<(const RationalNumber& other) const 
{

}

bool RationalNumber::operator<=(const RationalNumber& other) const 
{
    return (*this < other) || (*this == other);
}

bool RationalNumber::operator>(const RationalNumber& other) const 
{
    return !(*this <= other);
}

bool RationalNumber::operator>=(const RationalNumber& other) const 
{
    return !(*this < other);
}

// Input/output stream overloads
istream& operator>>(istream& is, RationalNumber& rn)
{

}


ostream& operator<<(ostream& os, const RationalNumber& rn) 
{}