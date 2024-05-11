#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point
{
    friend std::istream& operator>>(std::istream&, Point&);
    friend std::ostream& operator<<(std::ostream&, const Point&);
public:
    Point();
    Point(int, int);
private:
    int xCoordinate;
    int yCoordinate;

};

#endif