#include "TwoDayPackage.h"


TwoDayPackage::TwoDayPackage(const string& sName, const string& sAddress, const string& sCity,
                const string& sState, const string& sZip, const string& rName,
                const string& rAddress, const string& rCity, const string& rState,
                const string& rZip, double weight_, double costPerOunce_, double fee_)
                : Package(sName, sAddress, sCity, sState, sZip, rName, rAddress, rCity, rState, rZip, weight_, costPerOunce_),
                fee(fee_){}

double TwoDayPackage::calculateCost() const
{
    return Package::calculateCost() + fee;
}