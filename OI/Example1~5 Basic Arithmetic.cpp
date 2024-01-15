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
void add(int a[], int b[], int lena, int lenb)
{
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
void subtract(int a[], int b[], string& chara, string& charb, int lena, int lenb)
{
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

void multiply(int a[], int b[], string& chara, string& charb, int lena, int lenb)
{
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
    while (c[maxlen - 1] == 0 && maxlen > 1) maxlen--;//The highest 0 does not output
    
    for (int i = maxlen - 1; i >= 0; i--)
    {
        cout << c[i];
    }
    cout << endl;
}

int main()
{
    string chara, charb;
    int a[256] = {0}, b[256] = {0};

    //Addition
    cout << "1. Addition" << endl;
    cout << "Please enter two numbers: " << endl;
    getline(cin, chara);
    getline(cin, charb);
    int lena = chara.size(), lenb = charb.size();
    init(chara, a);
    init(charb, b);
    add(a, b, lena, lenb);

    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    
    //Subtraction
    cout << "2. Subtraction" << endl;
    cout << "Please enter the minuend: " << endl;//minuend 被减数 
    getline(cin, chara);
    cout << "Please enter the subtrahend (must be smaller than the minuend): " << endl;//subtrahend 减数
    getline(cin, charb);
    lena = chara.size(), lenb = charb.size();

    subtract(a, b, chara, charb, lena, lenb);

    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    
    //Multiplication
    cout << "3. Multiplication" << endl;
    cout << "Please enter two numbers: " << endl;
    getline(cin, chara);
    getline(cin, charb);
    lena = chara.size(), lenb = charb.size();
    init(chara, a);
    init(charb, b);
    multiply(a, b, chara, charb, lena, lenb);

    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    
    return 0;
}