#include "Time.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

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
void Time::printUniversal() const
{
    cout << setfill('0') << setw(2) << getHour() << ':'
         << setw(2) << getMinute() << ':'
         << setw(2) << getSecond() << endl;
}

void Time::printStandard() const
{
    cout << ((getHour() == 0) || (getHour() == 12) ? 12 : getHour() % 12)
         << ':' << setfill('0') << setw(2) << getMinute() << ':'
         << setw(2) << getSecond() << (hour < 12 ? " AM" : " PM") << endl;
}

int main()
{
    Time t1(23, 59, 0, 0);

    for (unsigned int i = 0; ; ++i) 
    {
        if (t1.getHour() % 12 == 1 && t1.getMinute() == 1)
            break;
        
        t1.setTick((t1.getTick() + 1) % 1000); 
        
        if (t1.getTick() == 0) 
        {            
            t1.printStandard();
            t1.setSecond((t1.getSecond() + 1) % 60);
            if (t1.getSecond() == 0) 
            {
                
                t1.setMinute((t1.getMinute() + 1) % 60);
                if (t1.getMinute() == 0) 
                {
                    t1.setHour((t1.getHour() + 1) % 24);
                }
            }

        }
    }

    return 0;
}