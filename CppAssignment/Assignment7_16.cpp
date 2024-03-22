#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() 
{
    const int rolls = 36000;

    int frequencies[13] = {};

    srand(time(0));

    for (int i = 0; i < rolls; i++)
    {
        int dice1 = rand() % 6 + 1;
        int dice2 = rand() % 6 + 1;
        int sum = dice1 + dice2;
        frequencies[sum]++;
    }

    cout << "Sum\tFrequency" << endl;
    for (int i = 2; i <= 12; ++i) 
    {
        cout << i << "\t" << frequencies[i] << endl;
    } 

    return 0;
}
