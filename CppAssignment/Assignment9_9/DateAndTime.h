#include "Time.h"

class DateAndTime: public Date, public Time 
{
public:

    DateAndTime(int month, int day, int year, int hour, int minute, int second, int tick);

    void tick();
    void setTimeAndDate(int hour, int minute, int second, int tick, int month, int day, int year);
    void printStandard();    //mm-dd-yyyy hh:mm:ss
    void printUniversal();   //mm-dd-yyyy hh:mm:ss AM/PM

};