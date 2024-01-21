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
void add(string &chara, string &charb)
{
    int a[256] = {0}, b[256] = {0};
    init(chara, a);
    init(charb, b);
    
    int lena = chara.length(), lenb = charb.length();
    int maxlen = max(lena, lenb);
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
void subtract(string& chara, string& charb)
{
    int a[256] = {0}, b[256] = {0};
    init(chara, a);
    init(charb, b);
    int lena = chara.length(), lenb = charb.length();
    string n; //Temporary array
    int c[256] = {0}, lenc;//The result

    //To determine if the minuend is larger
    if (lena < lenb || (lena == lenb && chara.compare(charb) < 0))//compare() belongs to c++ while strcmp() belongs to c 
    {
        n = charb;
        charb = chara;
        chara = n;
        cout << "-";//a < b, then a-b is negative
    }
    init(chara, a);
    init(charb, b);

    int i = 0;
    for (i; i < lena || i < lenb; i++)
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
void multiply(string& chara, string& charb)
{
    int a[256] = {0}, b[256] = {0};
    init(chara, a);
    init(charb, b);
    int lena = chara.length(), lenb = charb.length();
    
    int c[256] = {0};//The result
    int maxlen = lena + lenb;
    
    for (int i = 0; i < lena; i++)// You can understand this by using mathmatical induction on vertical calculation(starts with index 0)
    {
        for (int j = 0; j < lenb; j++)
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
void div1(int x, string chara)//x is divisor
{    
    int lena = chara.size();
    int a[256] = {0};
    init(chara, a);

    int c[256] = {0};
    int remainder = 0;//remainder 余数

    for (int i = lena - 1;i >= 0;i--)
    {
		remainder = remainder * 10 + a[i]; //模拟竖式除法中的落位 
		c[i] = remainder / x;
		remainder %= x;
    }
    
    //Remove the highest 0
    while (c[lena - 1] == 0 && lena > 1) lena--;
    
    //Print the result
    for (int i = lena - 1; i >= 0; i--)
    {
        cout << c[i];
    }
    
    //If remainder isn't zero, print the remainder
    if(remainder)
    {
        cout << "\nremainder: " << remainder;
    }
}

//6. Division (high/high)
//第一个数据用于存储数组长度
void div2(string chara, string charb)
{
    int tmp[256] = {0}, c = 0;
    init(chara);
    init(charb);
}

//将p中的元素复制到q中，并将q中的元素后移n个位置
void numcpy(int p[], int q[], int n)
{

}


int main()
{
    string chara, charb;
    int x;

    //Addition
    cout << "1. Addition" << endl;
    cout << "Please enter two numbers: " << endl;
    getline(cin, chara);
    getline(cin, charb);

    add(chara, charb);

    //Subtraction
    cout << "2. Subtraction" << endl;
    cout << "Please enter the minuend: " << endl;//minuend 被减数 
    getline(cin, chara);
    cout << "Please enter the subtrahend (must be smaller than the minuend): " << endl;//subtrahend 减数
    getline(cin, charb);

    subtract(chara, charb);
    
    //Multiplication
    cout << "3. Multiplication" << endl;
    cout << "Please enter two numbers: " << endl;
    getline(cin, chara);
    getline(cin, charb);

    multiply(chara, charb);

    //Division (high/low)
    cout << "4. Division (high/low)" << endl;
    cout << "Please enter the dividened (high precision):" << endl;
    getline(cin, chara);

    cout<< "Please enter the divisor (low precision):" << endl;
    cin >> x;
    div1(x, chara);
    
    return 0;
}