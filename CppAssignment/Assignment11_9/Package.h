#pragma once
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

private:
    string senderName, senderAddress, senderCity, senderState, senderZip;
    string recipientName, recipientAddress, recipientCity, recipientState, recipientZip;
    double weight;
    double costPerOunce;
};