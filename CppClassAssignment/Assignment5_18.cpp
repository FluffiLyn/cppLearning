#include <iostream>
#include <iomanip>
#include <bitset>
using namespace std;

int main()
{
    cout << "bin" << setw(9) << "oct" << setw(8) << "hex" << endl;
    for (int n = 1; n <= 256; n++)
    {
        cout << setw(9) << bitset<9>(n) << setw(8)  << oct << n << setw(8) << hex << n << endl;
    }

    return 0;

}