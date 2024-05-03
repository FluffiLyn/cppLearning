#include <string>
#include "Employee.h"
#pragma once

class CommissionEmployee : public Employee
{
public:
    CommissionEmployee(const std::string &, const std::string &,
                       const std::string &, int, int, int, double = 0.0, double = 0.0);
    virtual ~CommissionEmployee() = default; 

    void setCommissionRate(double);
    double getCommissionRate() const; 

    void setGrossSales(double);
    double getGrossSales() const;

    virtual double earnings() const override;
    virtual void print() const override;
    
private:
    double grossSales;
    double commissionRate;
};
