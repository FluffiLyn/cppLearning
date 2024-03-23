//Date.h
#ifndef DATE_H
#define DATE_H

class Date
{
public:
    explicit Date(int = 1, int = 1, int = 2000);

    unsigned int getMonth() const;
    unsigned int getDay() const;
    unsigned int getYear() const;
    
    void nextDay();
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    void printDate();
    
private:
    unsigned int month;
    unsigned int day;
    unsigned int year;
};



#endif

