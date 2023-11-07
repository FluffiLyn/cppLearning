#include <iostream>
#include <string>
#include <memory>
using namespace std;

//unique_ptr用于动态分配存储密码的内存，并在递归生成密码时传递指针引用，这样可以避免栈溢出的问题。
//prefix表示已经生成的部分密码
void generatePasswords(const string &charset, int maxlen, const string &prefix, unique_ptr<string[]> &passwords, int &count) 
{
    if (maxlen == 0) 
    {
        passwords[count++] = prefix;
        return;
    }
    for (char c : charset) //遍历charset的元素
    {
        string newPrefix = prefix + c;
        generatePasswords(charset, maxlen - 1, newPrefix, passwords, count);//递归
    }
}

//
unique_ptr<string[]> passgen(const string &charset, int maxlen, int &resultSize) 
{
    int size = 1;
    for (int i = 0; i < maxlen; ++i) 
    {
        size *= charset.length();
    }
    unique_ptr<string[]> passwords(new string[size]);
    int count = 0;
    generatePasswords(charset, maxlen, "", passwords, count);
    resultSize = count;
    return passwords;
}

int main() 
{
    cout << "Enter the characters for the charset (e.g., abc): ";
    string charset;
    cin >> charset;

    int maxlen;
    cout << "Enter the maximum length of the password: ";
    cin >> maxlen;

    int resultSize = 0;
    unique_ptr<string[]> passwords = passgen(charset, maxlen, resultSize);

    cout << "All possible passwords:" << endl;
    for (int i = 0; i < resultSize; i++) 
    {
        cout << passwords[i] << endl;
    }

    return 0;
}
