#include <iostream>
#include "Date.h"
using namespace std;

Date::Date(int m, int d, int y):month(m), day(d),year(y)
{
    if (m < 1 || m > 12)
    {
        cout << "Invalid month value. Month must be between 1 and 12." << endl;
        month = 1; 
    }
    else
        month = m;

    if (d < 1 || d > 31)
    {
        cout << "Invalid day value. Day must be between 1 and 31." << endl;
        day = 1; 
    }
    else 
        day = d;

    if (y < 0)
    {
        cout << "Invalid year value. Year must be non-negative." << endl;
        year = 0;
    }
    else
        year = y;
}

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

void Date::print()
{
    cout << month << "/" << day << "/" << year << endl;
}

int main()
{
    //测试闰年
    Date d1(1,1,2020);
    cout << "Today is: "; d1.print(); cout << endl;

    for (int i = 0; i < 60; i++)
    {
        d1.nextDay();
        cout << "Next day: "; d1.print();
    }

    //测试跨年
    Date d2(12,31,2019);
    cout << "Today is: "; d2.print();
    d2.nextDay();
    cout << "Next day: "; d2.print();

    //测试非法数据
    Date d3(13,31,2019);
    Date d4(1,32,2019);
    Date d5(1,1,-2019);
}
