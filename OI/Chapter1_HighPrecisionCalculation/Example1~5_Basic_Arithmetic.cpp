#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//1. We input a very long number and store it in the form of string
void init(string s, int a[])
{
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        a[i] = s[len - i - 1] - '0';//'x' - '0' = x - 0
    }
}

//2. Calculation
void add(string &charA, string &charB)
{
    int a[256] = {0}, b[256] = {0};
    init(charA, a);
    init(charB, b);
    
    int lenA = charA.length(), lenB = charB.length();
    int maxlen = max(lenA, lenB);
    int sum[256] = {0};
    
    for (int i = 0; i < maxlen; i++)
    {
        sum[i] = a[i] + b[i];

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
//This is equivalent to the following form:
/*
sum[i] = a[i] + b[i];
if (a[i] < b[i])
{
    sum[i] %= 10;
    sum[i+1]++;
}
*/


//3. Subtraction
void subtract(string& charA, string& charB)
{
    int a[256] = {0}, b[256] = {0};
    init(charA, a);
    init(charB, b);
    int lenA = charA.length(), lenB = charB.length();
    string n; //Temporary array
    int c[256] = {0}, lenc;//The result

    //To determine if the minuend is larger
    if (lenA < lenB || (lenA == lenB && charA.compare(charB) < 0))//compare() belongs to c++ while strcmp() belongs to c 
    {
        n = charB;
        charB = charA;
        charA = n;
        cout << "-";//a < b, then a-b is negative
    }
    init(charA, a);
    init(charB, b);

    int i = 0;
    for (i; i < lenA || i < lenB; i++)
    {
        if (a[i] < b[i])
        {
            a[i] += 10;//Borrow 10 from higher-order
            a[i+1] -= 1;
        }
        c[i] = a[i] - b[i];
    }
    lenc = i;
    while (c[lenc - 1] == 0 && lenc > 1) lenc--;//The highest 0 does not output

    for (int j = lenc - 1; j >= 0; j--)
    {
        cout << c[j];
    }
    cout << endl;
}

//4. Multiplication
void multiply(string& charA, string& charB)
{
    int a[256] = {0}, b[256] = {0};
    init(charA, a);
    init(charB, b);
    int lenA = charA.length(), lenB = charB.length();
    
    int c[256] = {0};//The result
    int maxlen = lenA + lenB;
    
    for (int i = 0; i < lenA; i++)// You can understand this by using mathmatical induction on vertical calculation(starts with index 0)
    {
        for (int j = 0; j < lenB; j++)
        {
            c[i + j] = a[i] * b[j];
            c[i + j + 1] += c[i + j] / 10;//Carry
            c[i + j] %= 10;//Carry
        }
    }
    //Remove the highest 0
    while (c[maxlen - 1] == 0 && maxlen > 1) maxlen--;
    
    for (int i = maxlen - 1; i >= 0; i--)
    {
        cout << c[i];
    }
    cout << endl;
}


//5.Division (high/low)
//一位数一位数地与除数相除，余数乘10加入下一位上
void div1(int x, string charA)//x is divisor
{    
    int lenA = charA.size();
    int a[256] = {0};
    init(charA, a);

    int c[256] = {0};
    int remainder = 0;//remainder 余数

    for (int i = lenA - 1;i >= 0;i--)
    {
		remainder = remainder * 10 + a[i]; //模拟竖式除法中的落位 
		c[i] = remainder / x;
		remainder %= x;
    }
    
    //Remove the highest 0
    while (c[lenA - 1] == 0 && lenA > 1) lenA--;
    
    //Print the result
    for (int i = lenA - 1; i >= 0; i--)
    {
        cout << c[i];
    }
    
    //If remainder isn't zero, print the remainder
    if(remainder)
    {
        cout << "\nremainder: " << remainder << endl;
    }
}

//6. Division (high/high)
//被除数a的最低位下标为min_dg。len是除数b的长度，避免反复计算。
//此函数用于判断a最低位是否能再减去除数b而保持非负
inline bool isGreater(int a[], int b[], int min_dg, int lenB)
{
    //若被除数剩余部分比除数长，则返回true
    if (a[min_dg + lenB] != 0) return true;

    //从高位到低位，逐位比较
    for (int i = lenB - 1; i >= 0; i--)
    {
        if (a[min_dg + i] > b[i]) return true;
        if (a[min_dg + i] < b[i]) return false;
    }
    //相等的情况也返回true
    return true;
}

void div2(string charA, string charB)
{
    //c是商，d是被除数的剩余部分，算法结束之后即为余数
    int a[256] = {0}, b[256] = {0}, c[256] = {0}, d[256] = {0};
    int lenA = charA.length(), lenB = charB.length();
    init(charA, a);init(charB, b);

    //若除数为0，直接结束。
    if (lenB == 0)
    {
        cout << "除数不能为0！" << endl; 
        return;
    }

    //一开始，除数的剩余部分是它本身
    for (int i = 0; i < lenA; i++)
    {
        d[i] = a[i];
    }
    
    //模拟竖式长除法的过程：从下标lenA-lenB开始，从高位到低位计算商
    //如果觉得太抽象，可以手算一遍竖式除法加以理解
    for (int i = lenA - lenB; i >= 0; i--)
    {
        //判断第i位（也即min_dg）是否为最低位
        //也即是否可以再减去除数而保持非负
        while(isGreater(d, b, i, lenB))
        {
            //高精度减法
            for (int j = 0; j < lenB; j++)
            {
                d[i + j] -= b[j];
                if (d[i + j] < 0)
                {
                    d[i + j + 1] -= 1;
                    d[i + j] += 10;
                }
            }
            c[i] += 1;
        }
    }
    //删除前导零
    while (c[lenA - 1] == 0 && lenA > 1) lenA--;
    
    //输出结果
    for (int i = lenA - 1; i >= 0; i--)
    {
        cout << c[i];
    }

    //若有余数则输出余数
    if(d[0])
    {
        cout << "\nThe remainder is: " << d[0] << endl;
    }
}


int main()
{
    string charA, charB;
    int x;

    //Addition
    cout << "1. Addition" << endl;
    cout << "Please enter two numbers: " << endl;
    getline(cin, charA);
    getline(cin, charB);

    add(charA, charB);

    //Subtraction
    cout << "2. Subtraction" << endl;
    cout << "Please enter the minuend: " << endl;//minuend 被减数 
    getline(cin, charA);
    cout << "Please enter the subtrahend (must be smaller than the minuend): " << endl;//subtrahend 减数
    getline(cin, charB);

    subtract(charA, charB);
    
    //Multiplication
    cout << "3. Multiplication" << endl;
    cout << "Please enter two numbers: " << endl;
    getline(cin, charA);
    getline(cin, charB);

    multiply(charA, charB);

    //Division (high/low)
    cout << "4. Division (high/low)" << endl;
    cout << "Please enter the dividened (high precision):" << endl;
    getline(cin, charA);

    cout<< "Please enter the divisor (low precision):" << endl;
    cin >> x;
    div1(x, charA);
    
    //Division (high/high)
    cout << "5. Division (high/high)" << endl;
    cout << "Please enter the dividened (high precision):" << endl;
    getline(cin, charA);

    cout<< "Please enter the divisor (high precision):" << endl;
    getline(cin, charB);
    div2(charA, charB);
    return 0;
}