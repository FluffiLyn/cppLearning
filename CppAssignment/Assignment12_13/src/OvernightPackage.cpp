#include "OvernightPackage.h"
using namespace std;

OvernightPackage::OvernightPackage(const string& sName, const string& sAddress, const string& sCity,
                const string& sState, const string& sZip, const string& rName,
                const string& rAddress, const string& rCity, const string& rState,
                const string& rZip, double weight_, double costPerOunce_, double additionalFee_)
                :Package(sName, sAddress, sCity, sState, sZip, rName, rAddress, rCity, rState, rZip, weight_, costPerOunce_),additionalFeePerOunce(additionalFee_)
                {}
double OvernightPackage::calculateCost()
{
	return (Package::calculateCost() + (Package::calculateCost() * getWeight()));
}
