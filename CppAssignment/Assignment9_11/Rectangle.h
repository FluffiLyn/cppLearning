#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:

    Rectangle(double, double);
    Rectangle();

    void setLength(double);
    void setWidth(double);
    
    double getLength();
    double getWidth();
    double getArea(double, double);
    double getPerimeter(double, double);

private:
    double length = 1.0;
    double width = 1.0;
};

#endif