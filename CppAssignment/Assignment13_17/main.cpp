#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << setw(7) << "Decimal" << setw(9) << "Octal" << setw(15)
         << "Hexadecimal" << setw(13) << "Character"
         << '\n';

    for (int i = 33; i <= 126; ++i)
        cout << setw(7) << dec << i << setw(9) << oct << i
             << setw(15) << hex << i << setw(13)
             << static_cast<char>(i) << endl;

    return 0;
}