#include <iostream>
#include "Rectangle.h"
using namespace std;

int main()
{
    Rectangle rectangle(5.0, 10.0);
    rectangle.draw();

    Rectangle rectangle2(10.0,10.0);
    rectangle2.setFillCharacter('#');
    rectangle2.setPerimeterCharacter('$');
    rectangle2.draw();

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

// Implementations for added functions
void Rectangle::draw()
{
    int x1 = 0, y1 = 0, x2 = min(25, static_cast<int>(length)), y2 = min(25, static_cast<int>(width));
    drawRectangle(x1, y1, x2, y2);
}

void Rectangle::setFillCharacter(char newFillChar)
{
    fillChar = newFillChar;
}

void Rectangle::setPerimeterCharacter(char newBorderChar)
{
    borderChar = newBorderChar;
}

// Helper function to draw the rectangle within the specified coordinates
void Rectangle::drawRectangle(int startX, int startY, int endX, int endY)
{
    // Draw top and bottom borders
    for (int i = startX; i <= endX; i++)
        cout << borderChar;
    cout << endl;

    // Draw left and right borders and fill
    for (int y = startY + 1; y < endY; y++)
    {
        cout << borderChar;
        for (int x = startX + 1; x < endX; x++)
            cout << fillChar;
        cout << borderChar << endl;
    }

    // Draw top border again
    for (int i = startX; i <= endX; ++i)
        cout << borderChar;
    cout << endl;
}