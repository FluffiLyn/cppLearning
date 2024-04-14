#include <cctype>
#include "HugeInt.h"

HugeInt::HugeInt(long value)
{
    for (short &element : integer)
        element = 0;

    for (size_t j = digits - 1; value != 0 && j >= 0; --j)
    {
        integer[j] = value % 10;
        value /= 10;
    }
}

HugeInt::HugeInt(const std::string &number)
{
    for (short &element : integer)
        element = 0;

    size_t lenght = number.size();

    for (size_t j = digits - lenght, k = 0; j < digits; ++j, ++k)
        if (isdigit(number[k]))
            integer[j] = number[k] - '0';
}

HugeInt HugeInt::operator+(const HugeInt &other) const
{
    HugeInt temp;
    int carry = 0;

    for (int i = digits - 1; i >= 0; --i)
    {
        temp.integer[i] = integer[i] + other.integer[i] + carry;

        if (temp.integer[i] > 9)
        {
            temp.integer[i] %= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
    }

    return temp;
}

HugeInt HugeInt::operator+(int other) const
{
    return (*this + HugeInt(other));
}

HugeInt HugeInt::operator+(const std::string &other) const
{
    return (*this + HugeInt(other));
}

HugeInt HugeInt::operator*(const HugeInt &other) const
{
    HugeInt temp(0), product(0);

    for (; temp < other; temp = temp + HugeInt(1))
    {
        product = product + *this;
    }

    return product;
}

HugeInt HugeInt::operator*(int other) const
{
    return (*this * HugeInt(other));
}

HugeInt HugeInt::operator*(const std::string &other) const
{
    return (*this * HugeInt(other));
}

HugeInt HugeInt::operator/(const HugeInt &other) const
{
    HugeInt result(0);

    if (other == result)
    {
        throw "divided by zero\n";
        return result;
    }
    if (*this < other)
    {
        return result;
    }
    while ((result * other + other) <= *this)
    {
        result = result + HugeInt(1);
    }

    return result;
}

HugeInt HugeInt::operator/(int other) const
{
    return (*this / HugeInt(other));
}

HugeInt HugeInt::operator/(const std::string &other) const
{
    return (*this / HugeInt(other));
}

bool HugeInt::operator==(const HugeInt &other) const
{
    return (integer == other.integer);
}

bool HugeInt::operator!=(const HugeInt &other) const
{
    return (!operator==(other));
}

bool HugeInt::operator>(const HugeInt &other) const
{
    return (integer > other.integer);
}

bool HugeInt::operator>=(const HugeInt &other) const
{
    return ((integer > other.integer) || (integer == other.integer));
}

bool HugeInt::operator<(const HugeInt &other) const
{
    return (integer < other.integer);
}

bool HugeInt::operator<=(const HugeInt &other) const
{
    return (integer < other.integer) || (integer == other.integer);
}

std::ostream &operator<<(std::ostream &output, const HugeInt &num)
{
    size_t i;

    for (i = 0; (0 == num.integer[i]) && (i < HugeInt::digits); ++i)
    {
        ;
    }

    if (i == HugeInt::digits)
    {
        output << 0;
    }
    else
    {
        for (; i < HugeInt::digits; ++i)
        {
            output << num.integer[i];
        }
    }

    return output;
}