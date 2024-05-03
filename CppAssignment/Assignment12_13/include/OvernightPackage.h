#include "Package.h"

class OvernightPackage : public Package 
{
public:

    OvernightPackage(const string&, const string&, const string&, 
                     const string&, const string&, const string&, 
                     const string&, const string&, const string&, 
                     const string&, double, double, double);

    double calculateCost();

private:
    double additionalFeePerOunce;
};