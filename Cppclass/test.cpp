#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct person
{
    char name[10];
    unsigned int id;
    double salary;
};

person allone[6];

int main()
{
    int i;
    person temp;
    for (i = 0; i < 6; i++)
    {
        cout << i << ": name: ";
        cin.getline(allone[i].name,10);
        cout << "id: ";
        cin >> allone[i].id;
        cout << "salary: ";
        cin >> allone[i].salary;
        cout << endl;
    }
    
    //sort by "salary"
    sort(allone[1], allone[5]);

    for (i = 0; i < 6; i++)
    return 0;
}