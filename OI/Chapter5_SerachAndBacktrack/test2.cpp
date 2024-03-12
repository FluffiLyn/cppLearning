#include <iostream>
#include <cmath>
using namespace std;

int arr[20] = {0};
bool b[20] = {0};

void search(int);
bool isValid(int, int);

int main()
{
    search(1);
    return 0;
}

bool isValid(int x, int y)
{
    int k = 2, sum = x + y;
    for (k; k <= sqrt(sum); k++)
    {
        if (sum % k == 0) return false;
    }
    return true;
}