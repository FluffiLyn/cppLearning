#include "Package.h"
#include <iostream>
Package::Package(const string& sName, const string& sAddress, const string& sCity,
                const string& sState, const string& sZip, const string& rName,
                const string& rAddress, const string& rCity, const string& rState,
                const string& rZip, double weight_, double costPerOunce_)
            : senderName(sName), senderAddress(sAddress), senderCity(sCity),
            senderState(sState), senderZip(sZip), recipientName(rName),
            recipientAddress(rAddress), recipientCity(rCity), recipientState(rState),
            recipientZip(rZip), weight(weight_), costPerOunce(costPerOunce_)
    {
        if (weight <= 0 || costPerOunce <= 0) 
        {
            cout << "Invalid package data" << endl;
            weight = 0; costPerOunce = 0;
        }
    }

double Package::calculateCost() const 
{
    return weight * costPerOunce;
}

double Package::getWeight() const 
{
    return weight;
}


string Package::getSenderName() const {
    return senderName;
}

string Package::getSenderAddress() const {
    return senderAddress;
}

string Package::getSenderCity() const {
    return senderCity;
}

string Package::getSenderState() const {
    return senderState;
}

string Package::getSenderZip() const {
    return senderZip;
}

string Package::getRecipientName() const {
    return recipientName;
}

string Package::getRecipientAddress() const {
    return recipientAddress;
}

string Package::getRecipientCity() const {
    return recipientCity;
}

string Package::getRecipientState() const {
    return recipientState;
}

string Package::getRecipientZip() const {
    return recipientZip;
}