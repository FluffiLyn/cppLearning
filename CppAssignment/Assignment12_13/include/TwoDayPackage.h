#include "Package.h"

class TwoDayPackage : public Package
{
public:
    TwoDayPackage(const string&, const string&, const string&,
            const string&, const string&, const string&,
            const string&, const string&, const string&,
            const string&, double, double, double);

    double calculateCost() const;
private:
    double fee;
};


