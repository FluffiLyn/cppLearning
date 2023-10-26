#include <iostream>
using namespace std;

int main()
{
    int num,tmp1,tmp2,tmp3,tmp4,tmp5;

    cout << "Please Enter a five-digit number:" ;
    cin >> num;

    tmp1 = num % 10;
    tmp2 = num / 10 % 10;
    tmp3 = num / 100 % 10;
    tmp4 = num / 1000 % 10;
    tmp5 = num / 10000;

    if(tmp1 == tmp5 && tmp2 == tmp4)
        cout << "\nThis is a palindrome." << endl;
    else
        cout << "\nThis is not a palindrome." << endl;
    
    return 0;

}