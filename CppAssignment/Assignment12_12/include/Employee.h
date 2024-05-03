#include <string> 
#include "Date.h"
#pragma once

class Employee
{
public:
    Employee(const std::string &, const std::string &, const std::string &, int, int, int);
    virtual ~Employee() = default; 

    void setFirstName(const std::string &); 
    std::string getFirstName() const;

    void setLastName(const std::string &); 
    std::string getLastName() const;

    void setSocialSecurityNumber(const std::string &); 
    std::string getSocialSecurityNumber() const; 

    void setBirthDay(int, int, int);
    Date getBirthDay() const;

    virtual double earnings() const = 0; 
    virtual void print() const;
private:
    std::string firstName;
    std::string lastName;
    std::string socialSecurityNumber;
    Date birthDate;
};
