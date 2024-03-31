#include <string>
#include <iostream>
using namespace std;

class HugeInteger
{
public:
    HugeInteger(string);
    HugeInteger();

    int num[40] = {0};
    void input(string);
    void output();
    int getLength();
    
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

//倒序输入
HugeInteger::HugeInteger(string str)
{
    this->length = str.length();
    for (int i = 0; i < length; i++)
    {
        num[i] = str[length - i - 1] - '0';
    }
}

HugeInteger::HugeInteger()
{
    this->length = 0;
}

void HugeInteger::input(string str)
{
    this->length = str.length();
    for (int i = 0; i < length; i++)
    {
        num[i] = str[length - i - 1] - '0';
    }
}

//倒序输出
void HugeInteger::output()
{
    for (int i = 39; i >= 0; i--)
    {
        if (num[i] != 0)
        {
            cout << num[i];
        }
    }
}

int HugeInteger::getLength()
{
    return this->length;
}

void HugeInteger::add(HugeInteger b)
{
    int lenA = this->getLength(), lenB = b.getLength();
    int maxlen = max(lenA, lenB);
    int sum[41] = {0};
    
    for (int i = 0; i < maxlen; i++)
    {
        sum[i] = this->num[i] + b.num[i];

    }
    for (int i = 0; i < maxlen; i++)
    {
        sum[i+1] += sum[i] / 10;
        sum[i] %= 10;
    }
    
    if(sum[maxlen] > 0)//Whether the number overflows
    {
		maxlen++;
	} 
    
    for (int j = maxlen - 1; j >= 0; j--)
        cout << sum[j];
    
    cout << endl;
}

void HugeInteger::subtract(HugeInteger b)
{
    HugeInteger n; 
    int c[40] = {0}, lenc;

    //判断被减数与减数的大小关系
    //若小于，则为负数，加上负号
    if (this->isLessThan(b))
    {
        n = b;
        b = *this;
        *this = n;
        cout << "-";
    }

    int i = 0;
    for (i; i < this->getLength() || i < b.getLength(); i++)
    {
        if (this->num[i] < b.num[i])
        {
            this->num[i] += 10;//借位
            this->num[i+1] -= 1;
        }
        c[i] = this->num[i] - b.num[i];
    }
    lenc = i;
    while (c[lenc - 1] == 0 && lenc > 1) lenc--;//删去前导0

    for (int j = lenc - 1; j >= 0; j--)
    {
        cout << c[j];
    }
    cout << endl;
}

void multiply(HugeInteger);
void divide(HugeInteger);
void modulus(HugeInteger);

bool isEqualTo(HugeInteger);
bool isNotEqualTo(HugeInteger);

bool HugeInteger::isGreaterThan(HugeInteger b)
{
    int maxlen = max(this->getLength(), b.getLength());
    // 比较长度，如果当前对象长度大于b的长度，则直接返回true
    if (this->getLength() > b.getLength())
    {
        return true;
    }
    // 如果长度相等，则逐位比较每一位数值大小
    else if (this->getLength() == b.getLength())
    {
        for (int i = maxlen - 1; i >= 0; i--)
        {
            if (this->num[i] > b.num[i])
            {
                return true;
            }
        }
        // 若所有对应位都相等，则等于，返回false
        return false;
    }
}

bool HugeInteger::isLessThan(HugeInteger b)
{
    int maxlen = max(this->getLength(), b.getLength());

    if (this->getLength() < b.getLength())
    {
        return true;
    }
    else if (this->getLength() == b.getLength())
    {
        for (int i = maxlen - 1; i >= 0; i--)
        {
            if (this->num[i] < b.num[i])
            {
                return true;
            }
        }
    }
    return false;
}

bool HugeInteger::isGreaterThanOrEqualTo(HugeInteger b)
{
    return !isLessThan(b);
}

bool HugeInteger::isLessThanOrEqualTo(HugeInteger b)
{
    return !isGreaterThan(b);
}