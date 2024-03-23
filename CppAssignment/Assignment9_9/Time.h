//Time.h
#include "Date.h"
#ifndef TIME_H
#define TIME_H

class Time
{
public:
    explicit Time(int = 0, int = 0, int = 0, int = 0);

    void setTime(int, int, int, int);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);
    void setTick(int);
    void ticking();

    unsigned int getHour() const;
    unsigned int getMinute() const;
    unsigned int getSecond() const;
    unsigned int getTick() const;

    void printUniversal();
    void printStandard();

private:
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
    unsigned int tick;
};


#endif
