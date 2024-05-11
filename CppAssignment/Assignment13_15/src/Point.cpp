#include "Point.h"
using namespace std;

Point::Point(){}
Point::Point(int x, int y) : xCoordinate(x), yCoordinate(y){}

// Input format should be (x,y), NOT x y
istream& operator>>(istream& input, Point& point)
{
	if (cin.peek() != '(')
		cin.clear(ios::failbit);
	else
		input.ignore();
	
	cin >> point.xCoordinate;

	if (cin.peek() != ',')
		cin.clear(ios::failbit);
	else
	{
		input.ignore();
		if (cin.peek() == ' ')
			input.ignore();
		else 
			cin.clear(ios::failbit);
	}

	cin >> point.yCoordinate;

	if (cin.peek() == ')')
		input.ignore();
	else
		cin.clear(ios::failbit);
	return cin;
}

ostream& operator<<(ostream& output, const Point& point)
{
	if(!cin.fail())
		output << '(' << point.xCoordinate << ", " << point.yCoordinate << ')';
	else
		output << "Error: Invalid data." << endl;
	
	return cout;
}


