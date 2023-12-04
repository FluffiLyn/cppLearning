#include <iostream>
using namespace std;
int main()
{
    int *p = NULL;
    p = new int(89);
    if (p == NULL)
    {
        cout << "allocation faliure\n";
        return 0;
    }
    cout << *p;
    delete p;
    return 0;
}