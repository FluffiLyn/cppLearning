#include "Rectangle.h"
#include <iostream>
using namespace std;
    
int main()
{
    Rectangle r1(3.6, 8.7);
    cout << "Perimeter of r1: " << r1.getPerimeter(r1.getLength(), r1.getWidth()) << endl;
    cout << "Area of r1: " << r1.getArea(r1.getLength(), r1.getWidth()) << endl;

    Rectangle r2(21.0, -1.1);

    return 0;
}


Rectangle::Rectangle(double length, double width)
{
    setLength(length);
    setWidth(width);
}

void Rectangle::setLength(double length)
{
    if (length <= 0.0 || length >= 20.0)
    {
        cout << "Invalid input. Length must be between 0.0 and 20.0" << endl;
        return;
    }
    else
        this->length = length;
}

void Rectangle::setWidth(double width)
{
    if (width <= 0.0 || width >= 20.0)
    {
        cout << "Invalid input. Width must be between 0.0 and 20.0" << endl;
        return;
    }
    else
        this->width = width;
}

double Rectangle::getLength()
{
    return length;
}

double Rectangle::getWidth()
{
    return width;
}

double Rectangle::getPerimeter(double length, double width)
{
    return 2 * (length + width);
}
    
double Rectangle::getArea(double length, double width)
{
    return length * width;
}
