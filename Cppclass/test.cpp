#include <iostream>
using namespace std;

int main()
{
    int b[] = {10, 20, 30, 40};
    int *bPtr = b;

    cout << "Array b printed with:\n\nArray subscript notation: " << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << "b[]" << i << "] = " << b[i] << '\n';
    }

    cout << "\nPointer/offset notation where the pointer is the array name\n";

    for (int offset1 = 0; offset1 < 4; offset1++)
        cout << "*(b + " << offset1 << ") = " << *(b + offset1) << endl;

    return 0;
}