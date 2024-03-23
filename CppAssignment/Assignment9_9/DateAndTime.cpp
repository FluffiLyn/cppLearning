#include "DateAndTime.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;
int main()
{
    cout << "Test incrementing to the next day" << endl;
    DateAndTime dt1(3, 23, 2024, 23, 59, 50, 0);
    for (int i = 0; i < 100000; i++)
    {
        if (dt1.getTick() == 0)
            dt1.printUniversal();
        dt1.tick();
    }

    cout<< "Test incrementing to the next month" << endl;
    DateAndTime dt2(3,31,2024,23,59,50,0);
    for (int i = 0; i < 100000; i++)
    {
        if (dt2.getTick() == 0)
            dt2.printUniversal();
        dt2.tick();
    }

    cout << "Test incrementing to the next year" << endl;
    DateAndTime dt3(12, 31, 2024, 23, 59, 50, 0);
    for (int i = 0; i < 100000; i++)
    {
        if (dt3.getTick() == 0)
            dt3.printUniversal();
        dt3.tick();
    }

    return 0;
}


//Time.h
Time::Time(int hour, int minute, int second, int tick)
{
    setTime(hour, minute, second, tick);
}

void Time::setTime(int h, int m, int s, int t)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
    setTick(t);
}

void Time::setHour(int h)
{
    if (h >= 0 && h < 24)
        hour = h;
    else
        throw invalid_argument("hour must be 0-23");
}

void Time::setMinute(int m)
{
    if (m >= 0 && m < 60)
        minute = m;
    else
        throw invalid_argument("minute must be 0-59");
}

void Time::setSecond(int s)
{
    if (s >= 0 && s < 60)
        second = s;
    else
        throw invalid_argument("second must be 0-59");
}

void Time::setTick(int t)
{
    if (t >= 0 && t < 1000)
        tick = t;
    else
        throw invalid_argument("tick must be 0-999");
}

void Time::ticking()
{
    if (getTick() < 999)
        setTick(getTick() + 1);
    else
    {
        setTick(0);
        if (getSecond() < 59)
            setSecond(getSecond() + 1);
        else
        {
            setSecond(0);
            if (getMinute() < 59)
                setMinute(getMinute() + 1);
            else
            {
                setMinute(0);
                if (getHour() < 23)
                    setHour(getHour() + 1);
                else
                {
                    setHour(0);
                }
            }
        }
    }
}


unsigned int Time::getHour() const
{
    return hour;
}

unsigned int Time::getMinute() const
{
    return minute;
}

unsigned int Time::getSecond() const
{
    return second;
}

unsigned int Time::getTick() const
{
    return tick;
}

void Time::printStandard()
{
    cout << ((getHour() == 0) || (getHour() == 12) ? 12 : getHour() % 12)
     << ':' << setfill('0') << setw(2) << getMinute() << ':'
     << setw(2) << getSecond() << (getHour() < 12 ? " AM" : " PM") << endl;
}

void Time::printUniversal()
{
    cout << setfill('0') << setw(2) << getHour() << ':'
         << setw(2) << getMinute() << ':'
         << setw(2) << getSecond() << endl;
}


//Date.h
Date::Date(int m, int d, int y):month(m), day(d),year(y)
{
    setMonth(month);
    setDay(day);
    setYear(year);
}

void Date::setDay(int d)
{
    if (d < 1 || d > 31) 
        throw invalid_argument("Invalid day value. Day must be between 1 and 31.");
    else 
        day = d;
}

void Date::setMonth(int m)
{
    if (m < 1 || m > 12) 
        throw invalid_argument("Invalid month value. Month must be between 1 and 12.");
    else 
        month = m;
}

void Date::setYear(int y)
{
    if (y < 0)
        throw invalid_argument("Invalid year value. Year must be non-negative.");
    else
        year = y;
}


unsigned int Date::getMonth() const
{
    return month;
}

unsigned int Date::getDay() const
{
    return day;
}

unsigned int Date::getYear() const
{
    return year;
}

//为省力，此处不使用getter
void Date::nextDay()
{
    //是否跨年
    if (month == 12 && day == 31)
    {
        month = 1;
        day = 1;
        year++;
    }
    else if (month == 2)//是否为闰年二月
    {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)//是，则判断是否为29日
        {
            if (day == 29)
            {
                day = 1;
                month++;
            }
            else
            {
                day++;
            }
        }
        else//不是，则判断是否为28日
        {
            if (day == 28)
            {
                day = 1;
                month++;
            }
            else
            {
                day++;
            }
        }
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)//是否为大月
    {
        if (day == 31)
        {
            day = 1;
            month++;
        }
        else
        {
            day++;
        }
    }
    else
    {
        if (day == 30)
        {
            day = 1;
            month++;
        }
        else
        {
            day++;
        }
    }

}

void Date::printDate()
{
    cout << month << "/" << day << "/" << year << " ";
}

//DateAndTime.h
DateAndTime::DateAndTime(int month, int day, int year, int hour, int minute, int second, int tick) 
    : Date(month, day, year), Time(hour, minute, second, tick) {}


void DateAndTime::tick()
{
    ticking();
    if(getHour() == 0 && getMinute() == 0 && getSecond() == 0 && getTick() == 0)
        nextDay();

}


void DateAndTime::printStandard() 
{
    printDate();
    Time::printStandard();
}

void DateAndTime::printUniversal() 
{
    printDate();
    Time::printUniversal();
}
