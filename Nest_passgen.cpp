#include <iostream>
#include <string>
using namespace std;

void passgen(const char* charSet, size_t sizeofSet, int len, string current)
{
    if(len == 0)
    {
        cout << current << endl;
        return;
    }
    
    for(int i = 0; i < sizeofSet; i++)
    {
        string newString = current + charSet[i];
        passgen(charSet, sizeofSet, len - 1, newString);
    }
}

int main()
{
    string charSet;
    int maxLen;

    cout << "Please enter the string (e.g. abc):";
    cin >> charSet;

    cout << "Please enter the max length of the passwords"; 
    cin >> maxLen;

    passgen(charSet.c_str(), charSet.length(), maxLen, "");

    return 0;
}