#include <iostream>
using namespace std;
int main () 
{
    char c;
    int n;
    char str[256];
    cout << "Enter a word: ";
    cin >> c;
    cin.putback (c);
    cin >> str;
    cout << " You have entered word " << str << endl;
    return 0;
}