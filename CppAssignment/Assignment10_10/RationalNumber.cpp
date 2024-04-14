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
    numerator(deno > 0 ? nume : -nume), denominator(deno > 0 ? deno : -deno)
    {
        if (denominator == 0) 
        {
            throw invalid_argument("Denominator cannot be zero.");
        }
        
        int gcd = gcd_(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;

        if (denominator < 0) 
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }


RationalNumber RationalNumber::operator+(const RationalNumber& other) const 
{
    return RationalNumber(numerator * other.denominator + denominator * other.numerator, denominator * other.denominator);
}

RationalNumber RationalNumber::operator-(const RationalNumber& other) const 
{
    return RationalNumber(numerator * other.denominator - denominator * other.numerator, denominator * other.denominator);
}

RationalNumber RationalNumber::operator*(const RationalNumber& other) const 
{
    return RationalNumber(numerator * other.numerator, denominator * other.denominator);
}

RationalNumber RationalNumber::operator/(const RationalNumber& other) const 
{
    return RationalNumber(numerator * other.denominator, denominator * other.numerator);
}

// Relational and equality operator overloads
bool RationalNumber::operator==(const RationalNumber& other) const 
{
    return (numerator * other.denominator == denominator * other.numerator);
}

bool RationalNumber::operator!=(const RationalNumber& other) const 
{
    return !(*this == other);
}

bool RationalNumber::operator<(const RationalNumber& other) const 
{
    return numerator * other.denominator - denominator * other.numerator > 0 && denominator * other.denominator < 0 
        || numerator * other.denominator - denominator * other.numerator < 0 && denominator * other.denominator > 0; 
}

bool RationalNumber::operator<=(const RationalNumber& other) const 
{
    return (!(*this > other));
}

bool RationalNumber::operator>(const RationalNumber& other) const 
{
    return numerator * other.denominator - denominator * other.numerator > 0 && denominator * other.denominator > 0 
        || numerator * other.denominator - denominator * other.numerator < 0 && denominator * other.denominator < 0;
}

bool RationalNumber::operator>=(const RationalNumber& other) const 
{
    return (!(*this < other));
}


// Input/output stream overloads
istream& operator>>(istream& cin, RationalNumber& rn)
{
    cin >> rn.numerator >> rn.denominator;
    return cin;
}


ostream& operator<<(ostream& cout, const RationalNumber& rn) 
{
    if (rn.numerator == rn.denominator)
       cout << 1;
    else if (rn.numerator == -rn.denominator)
       cout << -1; 
    else
    {
        cout << rn.numerator << "/" << rn.denominator;
    }
    return cout;
}