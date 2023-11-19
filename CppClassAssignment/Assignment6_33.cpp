#include <iostream>
#include <ctime>
using namespace std;

int flip()
{
    int result = rand() % 2;
    if (result == 1)
        return 1;
    else
        return 0;

}

int main()
{
    srand(time(0));
    int heads = 0;
    int tails = 0;
   
    for (int i = 0; i < 2147483646; ++i)
    {
        int result = flip();
        
        if (result == 1)
            heads++;
        else
            tails++;
    }
    cout << "Heads: " << heads << " ,  tails: " << tails << endl;

    return 0;
}