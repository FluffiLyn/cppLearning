#include <iostream>
#include <vector>
#include "OvernightPackage.h"
#include "TwoDayPackage.h"

int main()
{
    vector<Package*> packages(3);
    packages[0] = new Package("Alice", "123 Sender St", "Anytown", "CA", "12345",
              "Bob", "456 Recipient Ave", "Othertown", "NY", "67890", 16, 0.5);


    packages[1] = new TwoDayPackage("Zhangsan", "789 Another St", "Exampleville", "TX", "54321",
                     "Dave", "321 Receiver Rd", "Somewhere", "FL", "10293", 12, 0.6, 10);
 

    packages[2] = new OvernightPackage("Lisi", "987 Quick St", "Fastcity", "WA", "98765",
                        "Frank", "543 Rapid Ln", "Speedville", "AZ", "87654", 8, 0.7, 0.2);

    double totalShippingCost = 0;
    for (size_t i = 0; i < packages.size(); ++i)
    {
        cout << "Package " << i + 1 << "\n\nSender:\n"
                  << packages[i]->getSenderName() << '\n'
                  << packages[i]->getSenderAddress() << '\n'
                  << packages[i]->getSenderCity() << ", "
                  << packages[i]->getRecipientState() << ' '
                  << packages[i]->getSenderZip();
        cout << "\n\nRecipient:\n"
                  << packages[i]->getRecipientName()
                  << '\n'
                  << packages[i]->getRecipientAddress() << '\n'
                  << packages[i]->getRecipientCity() << ", "
                  << packages[i]->getRecipientState() << ' '
                  << packages[i]->getRecipientZip();
        double cost = packages[i]->calculateCost();
        cout << "\n\nCost: $" << cost << "\n\n";
        totalShippingCost += cost;
    }

    cout << "Total shipping cost: $" << totalShippingCost << endl;

    for (vector<Package*>::iterator it = packages.begin(); it != packages.end(); ++it)
    {
        delete *it;
    }
    return 0;
}