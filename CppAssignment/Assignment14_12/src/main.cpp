#include <iostream>
#include <fstream>
using namespace std;

bool checkNumber(char[]);
char word(char, int);

int main()
{

    char number[10];

    cout << "\n\nEnter a seven digit number: (no 1 or 0)";
    cin >> number;

    ofstream outFile("phone.dat", ios::out);

    if (!outFile)
    {
        cerr << "Unable to open the output file.";
        exit(EXIT_FAILURE);
    }

    if (checkNumber(number))
    {
        cout << "Invalid number: Number should not have 0 or 1";
        system("Pause");
    }
    else
    {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    for (int l = 0; l < 3; ++l)
                        for (int m = 0; m < 3; ++m)
                            for (int n = 0; n < 3; ++n)
                                for (int o = 0; o < 3; ++o)
                                    outFile << word(number[0], i)
                                            << word(number[1], j)
                                            << word(number[2], k)
                                            << word(number[3], l)
                                            << word(number[4], m)
                                            << word(number[5], n)
                                            << word(number[6], o)
                                            << "\n";

        return 0;
    }

    return 0;
}

bool checkNumber(char number[])
{
    bool flag = false;

    for (int i = 0; i < 1; ++i)
        if (number[i] == 48 || number[i] == 49 && flag == false)
            flag = true;

    return flag;
}

char word(char var, int a)
{
    if ((var < 55) || (var == 55 && a == 0))
        return ((static_cast<int>(var) - 49) * 3 + 62 + a);
    else if ((var > 55) || (var == 55 && a > 0))
        return ((static_cast<int>(var) - 49) * 3 + 63 + a);

    return 0;
}