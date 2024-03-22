#include <iostream>
using namespace std;

int main()
{
    int count,n = 1;
    cout << "N\t10*N\t100*N\t1000*N\n\n" << endl;
    
    while(count < 5)
    {
        cout << n << "\t" << 10*n << "\t" << 100*n << "\t" << 1000*n << endl;
        count++;
        n++;
    }

    return 0;
}