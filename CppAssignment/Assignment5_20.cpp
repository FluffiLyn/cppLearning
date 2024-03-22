#include <iostream>
using namespace std;

int main() 
{
    int maxSide = 500; // 定义边长的最大值

    for (int side1 = 1; side1 <= maxSide; side1++) 
    {
        for (int side2 = 1; side2 <= maxSide; side2++) 
        {
            for (int hypotenuse = 1; hypotenuse <= maxSide; hypotenuse++) 
            {
                if (side1 * side1 + side2 * side2 == hypotenuse * hypotenuse) 
                {
                    cout << "Side1: " << side1 << ", Side2: " << side2 << ", Hypotenuse: " << hypotenuse << endl;
                }
            }
        }
    }

    return 0;
}
