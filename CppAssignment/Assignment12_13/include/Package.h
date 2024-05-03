#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
using namespace std;

class Package 
{
public:
    Package(const string&, const string&, const string&,
            const string&, const string&, const string&,
            const string&, const string&, const string&,
            const string&, double, double);

    double calculateCost() const;
    double getWeight() const;
    
    string getSenderName() const;
    string getSenderAddress() const;
    string getSenderCity() const;
    string getSenderState() const;
    string getSenderZip() const;

    string getRecipientName() const;
    string getRecipientAddress() const;
    string getRecipientCity() const;
    string getRecipientState() const;
    string getRecipientZip() const;

private:
    string senderName, senderAddress, senderCity, senderState, senderZip;
    string recipientName, recipientAddress, recipientCity, recipientState, recipientZip;
    double weight;
    double costPerOunce;
};

#endif