#include <string>
#include <iostream>
using namespace std;

class HugeInteger
{
public:
    HugeInteger(string);
    HugeInteger();
    HugeInteger(const HugeInteger&);

    int num[40] = {0};
    void input(string);
    void output();
    int getLength();
    void setLength(int);
    
    void add(HugeInteger);
    void subtract(HugeInteger);
    void multiply(HugeInteger);
    void divide(HugeInteger);
    void modulus(HugeInteger);

    bool isEqualTo(HugeInteger);
    bool isNotEqualTo(HugeInteger);
    bool isGreaterThan(HugeInteger);
    bool isLessThan(HugeInteger);
    bool isGreaterThanOrEqualTo(HugeInteger);
    bool isLessThanOrEqualTo(HugeInteger);

private:
    int length;
};


