#include <iostream>
using namespace std;

const int SALESPERSON = 4;
const int PRODUCTS = 5;

void printTable(int sales[][SALESPERSON + 2]) 
{
    cout << "Product\t";
    for (int i = 1; i <= SALESPERSON; i++) 
    {
        cout << "Salesperson " << i << "\t";
    }
    cout << "\tTotal" << endl;

    // Print the table rows
    for (int i = 1; i <= PRODUCTS; i++) 
    {
        cout << "Product " << i << "\t";
        int rowTotal = 0;
        for (int j = 1; j <= SALESPERSON; j++) 
        {
            cout << sales[i][j] << "\t\t";
            rowTotal += sales[i][j];
        }
        cout << rowTotal << endl;
    }

    // Print the column totals
    cout << "Total\t\t";
    for (int i = 1; i <= SALESPERSON; i++) 
    {
        int colTotal = 0;
        for (int j = 1; j <= PRODUCTS; j++) 
        {
            colTotal += sales[j][i];
        }
        cout << colTotal << "\t\t";
    }

    // Print the overall total
    int overallTotal = 0;
    for (int i = 1; i <= PRODUCTS; i++)
    {
        overallTotal += sales[i][SALESPERSON + 1];
    }
    cout << overallTotal << endl;
}

int main() 
{
    int sales[PRODUCTS + 1][SALESPERSON + 2] = {};

    // Read the sales data for each salesperson
    for (int i = 1; i <= SALESPERSON; i++) 
    {
        cout << "Enter sales data for Salesperson " << i << endl;
        cout << "Product\t\tAmount ($)" << endl;

        for (int j = 1; j <= PRODUCTS; j++) 
        {
            cout << j << "\t\t";
            int amount;
            cin >> amount;
            sales[j][i] = amount;
            sales[j][SALESPERSON + 1] += amount;
        }
        cout << endl;
    }

    printTable(sales);

    return 0;
}
