#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
#include <array>
#include <string>

class HugeInt
{
    friend std::ostream &operator<<(std::ostream &, const HugeInt &);

public:
    static const int digits = 30;

    HugeInt(long = 0);
    HugeInt(const std::string &);
    HugeInt operator+(const HugeInt &) const;
    HugeInt operator+(int) const;
    HugeInt operator+(const std::string &) const;

    HugeInt operator*(const HugeInt &) const;
    HugeInt operator*(int) const;
    HugeInt operator*(const std::string &) const;

    HugeInt operator/(const HugeInt &) const;
    HugeInt operator/(int) const;
    HugeInt operator/(const std::string &) const;

    bool operator==(const HugeInt &) const;
    bool operator!=(const HugeInt &) const;
    bool operator>(const HugeInt &) const;
    bool operator>=(const HugeInt &) const;
    bool operator<(const HugeInt &) const;
    bool operator<=(const HugeInt &) const;

private:
    std::array<short, digits> integer;
};

#endif