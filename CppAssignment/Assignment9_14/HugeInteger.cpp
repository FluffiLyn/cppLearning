#include "HugeInteger.h"
using namespace std;

int main()
{
    HugeInteger a("999999999998888877777766666"), b("4"),c("999999999998888877777766667"),
    d("99999999999");
    cout << "a = " ; a.output(); cout << ", b = " ; b.output();
    cout << ", c = "; c.output(); cout << ", d = "; d.output(); cout << endl;
    
    cout << "a + b = "; a.add(b);
    cout << "a - c = "; a.subtract(c); 
    cout << "a * b = "; a.multiply(b);
    cout << "a * c = "; a.multiply(c); 
    cout << "a / b = "; a.divide(b);
    cout << "a / d = "; a.divide(d);
    return 0;
}

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

HugeInteger::HugeInteger(const HugeInteger& b)
{
    this->length = b.length;
    for (int i = 0; i < length; i++)
    {
        this->num[i] = b.num[i];
    }
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

void HugeInteger::setLength(int len)
{
    this->length = len;
}

void HugeInteger::add(HugeInteger b)
{
    int maxlen = max(this->getLength(), b.getLength());
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
    
    //判断是否有进位
    if(sum[maxlen] > 0)
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
    for (; i < this->getLength() || i < b.getLength(); i++)
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

void HugeInteger::multiply(HugeInteger b)
{
    int maxlen = getLength() + b.getLength();
    int c[40 + maxlen];   
    for (int i = 0; i < getLength(); i++)
    {
        for (int j = 0; j < b.getLength(); j++)
        {
            c[i + j] = num[i] * b.num[j];
            c[i + j + 1] += c[i + j] / 10;
            c[i + j] %= 10;
        }
    }

    while (c[maxlen - 1] == 0 && maxlen > 1) maxlen--;
    
    for (int i = maxlen - 1; i >= 0; i--)
    {
        cout << c[i];
    }
    cout << endl;
}
//被除数a的最低位下标为min_dg。len是除数b的长度，避免反复计算。
//此函数用于判断a最低位是否能再减去除数b而保持非负
inline bool isGreaterOrEq_ForDiv(HugeInteger x, HugeInteger y, int min_dg)
{
    //若被除数剩余部分比除数长，则返回true
    if (x.num[min_dg + y.getLength()] != 0) return true;

    //从高位到低位，逐位比较
    for (int i = y.getLength() - 1; i >= 0; i--)
    {
        if (x.num[min_dg + i] > y.num[i]) return true;
        if (x.num[min_dg + i] < y.num[i]) return false;
    }
    //相等的情况返回true
    return true;
}

void HugeInteger::divide(HugeInteger b)
{
    //c是商，d是被除数的剩余部分，算法结束之后即为余数
    int c[40] = {0};
    //若除数为0，直接结束。
    if (b.getLength() == 1 && b.num[0] == 0)
    {
        cout << "除数不能为0！" << endl; 
        return;
    }

    //一开始，除数的剩余部分是它本身
    HugeInteger d(*this);
    
    //模拟竖式长除法的过程：从下标lenA-lenB开始，从高位到低位计算商
    for (int i = getLength() - b.getLength(); i >= 0; i--)
    {
        //是否可以再减去除数而保持非负
        while(isGreaterOrEq_ForDiv(d,b,i))
        {
            //高精度减法
            for (int j = 0; j < b.getLength(); j++)
            {
                d.num[i + j] -= b.num[j];
                if (d.num[i + j] < 0)
                {
                    d.num[i + j + 1] -= 1;
                    d.num[i + j] += 10;
                }
            }
            c[i] += 1;
        }
    }
    //删除前导零
    int lenA = getLength();
    while (c[lenA - 1] == 0 && lenA > 1) lenA--;
    
    //输出结果
    for (int i = lenA - 1; i >= 0; i--)
    {
        cout << c[i];
    }

    //若有余数则输出余数
    if(d.num[0])
    {
        cout << "\nThe remainder is: " << d.num[0] << endl;
    }
}


void HugeInteger::modulus(HugeInteger a)
{
    //Nothing here
}

bool HugeInteger::isEqualTo(HugeInteger b)
{
    for (int i = 0; i < max(this->getLength(), b.getLength()); i++)
        if (num[i] != b.num[i]) return false;
    return true;
}

bool HugeInteger::isNotEqualTo(HugeInteger b)
{
    return !isEqualTo(b);
}

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
            if (this->num[i] > b.num[i]) return true;
    }
    // 若所有对应位都相等，则等于，返回false
    return false;
}

bool HugeInteger::isLessThan(HugeInteger b)
{
    int maxlen = max(this->getLength(), b.getLength());

    if (this->getLength() < b.getLength()) return true;
    else if (this->getLength() == b.getLength())
    {
        for (int i = maxlen - 1; i >= 0; i--)
            if (this->num[i] < b.num[i]) return true;
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