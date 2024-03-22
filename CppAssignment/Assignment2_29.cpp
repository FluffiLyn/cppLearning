#include <iostream>
using namespace std;

int main()
{
    cout << "integer\tsquare\tcube" << endl;  
    
    int a;
    for (a=0;a<11;a++)
        cout << a << "\t" << a*a << "\t" << a*a*a << endl;
        
    system("pause");
    return 0;
}