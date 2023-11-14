#include <iostream>
#include <cstring>
using namespace std;

void removeDuplicates(char* str) 
{
    if (str == nullptr)//如果引用的是空指针 
    {
        return;
    }

    int len = strlen(str);
    if (len < 2) {
        return; // 字符串长度小于2，不需要去重
    }

    int tail = 1;
    for (int i = 1; i < len; ++i)
    {
        int j;
        for (j = 0; j < tail; ++j) 
        {
            if (str[i] == str[j]) 
            {
                break;
            }
        }
        if (j == tail) 
        {
            str[tail] = str[i];
            ++tail;
        }
    }
    str[tail] = '\0'; // 添加字符串结尾标志
}

int main() {
    char input[100]; 
    cout << "Enter a string: ";
    cin.getline(input, 100);

    cout << "Original string: " << input << endl;

    removeDuplicates(input);

    cout << "String after removing duplicates: " << input << endl;

    return 0;
}
