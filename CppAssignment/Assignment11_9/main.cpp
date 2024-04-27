#include <iostream>
#include "OvernightPackage.h"
#include "TwoDayPackage.h"

int main()
{
    Package p("Alice", "123 Sender St", "Anytown", "CA", "12345",
              "Bob", "456 Recipient Ave", "Othertown", "NY", "67890", 16, 0.5);
    cout << "Standard Package Cost: $" << p.calculateCost() << endl;

    TwoDayPackage td("Zhangsan", "789 Another St", "Exampleville", "TX", "54321",
                     "Dave", "321 Receiver Rd", "Somewhere", "FL", "10293", 12, 0.6, 10);
    cout << "Two-Day Package Cost: $" << td.calculateCost() << endl;

    OvernightPackage ov("Lisi", "987 Quick St", "Fastcity", "WA", "98765",
                        "Frank", "543 Rapid Ln", "Speedville", "AZ", "87654", 8, 0.7, 0.2);
    cout << "Overnight Package Cost: $" << ov.calculateCost() << endl;

    return 0;
}