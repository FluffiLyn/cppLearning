#include <iostream>
#include <string>
using namespace std;

bool testPalindrome(const string& s, int start, int end) 
{
    //base case
    if (start >= end) 
    {
        return true;
    }

    if (s[start] == s[end]) 
    {
        return testPalindrome(s, start + 1, end - 1);
    } 
    else 
    {
        return false;
    }
}

int main() 
{
    string s;

    cout << "Please enter a string: ";
    getline(cin, s);
    if (testPalindrome(s, 0, s.length() - 1)) 
    {
          cout << "Yes, '" << s << "' is a palindrome." << endl;
    }
    else 
    {
        cout << "No, '" << s << "' is not a palindrome." << endl;
    }
    
    return 0;
}
