#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void moveTortoise(int &position) 
{
    int move = rand() % 10 + 1;
    if (move >= 1 && move <= 5)// Fast plod
    {
        position += 3;
    } 
    else if (move >= 6 && move <= 7) // Slip
    {
        position -= 6;
    } 
    else // Slow plod
    {
        position += 1;
    }
    if (position < 1) 
    {
        position = 1;
    }
}

void moveHare(int &position) 
{
    int move = rand() % 10 + 1;
    if (move >= 1 && move <= 2)// Sleep 
    {
        position += 0;
    } 
    else if (move >= 3 && move <= 4)// Big hop
    {
        position += 9;
    } 
    else if (move == 5)// Big slip
    {
        position -= 12;
    } 
    else if (move >= 6 && move <= 8)// Small hop
    {
        position += 1;
    } 
    else// Small slip
    {
        position -= 2;
    }
    if (position < 1) 
    {
        position = 1;
    }
}

int main() 
{
    srand(static_cast<unsigned int>(time(0)));
    int tortoisePos = 1;
    int harePos = 1;

    cout << "BANG !!! AND THEY'RE OFF!!!" << endl;

    while (tortoisePos < 70 && harePos < 70) 
    {
        moveTortoise(tortoisePos);
        moveHare(harePos);

        for (int i = 1; i <= 70; ++i) {
            if (tortoisePos == i && harePos == i) 
            {
                cout << "OUCH!!!";
            } 
            else if (tortoisePos == i) 
            {
                cout << "T";
            } 
            else if (harePos == i) 
            {
                cout << "H";
            } 
            else 
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    if (tortoisePos >= 70 && harePos < 70) 
    {
        cout << "TORTOISE WINS!!! YAY!!!" << endl;
    } 
    else if (harePos >= 70 && tortoisePos < 70) 
    {
        cout << "Hare wins. Yuch." << endl;
    } 
    else 
    {
        cout << "It's a tie" << endl;
    }

    return 0;
}
