#include <sstream>
#include "Employee.h" 
using namespace std;

Employee::Employee(const string &first, const string &last,
                   const string &ssn, int month, int day, int year)
    : firstName(first), lastName(last), socialSecurityNumber(ssn),
      birthDate(month, day, year)
{
}

void Employee::setFirstName(const string &first) { firstName = first; }

string Employee::getFirstName() const { return firstName; }

void Employee::setLastName(const string &last) { lastName = last; }

string Employee::getLastName() const { return lastName; }

void Employee::setSocialSecurityNumber(const string &ssn)
{
    socialSecurityNumber = ssn; 
}

string Employee::getSocialSecurityNumber() const
{
    return socialSecurityNumber;
}

void Employee::setBirthDay(int month, int day, int year)
{
    birthDate.setDate(month, day, year);
}

Date Employee::getBirthDay() const
{
    return birthDate;
}

void Employee::print() const
{
    std::cout << getFirstName() << " " << getLastName()
              << "\nbirthday: " << getBirthDay()
              << "\nsocial security number: " << getSocialSecurityNumber();
}