#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

const double TOLERANCE = 0.000001;
const double INF = 9999999.;

class Point 
{
public:
    double x;
    double y;
    bool operator < (const Point & point) const 
    {
        if (x != point.x)
            return x < point.x;
        else
            return y < point.y;
    }
    bool operator == (const Point & point) const 
    {
        return (fabs(x - point.x) < TOLERANCE && fabs(y - point.y) < TOLERANCE);
    }
};

class Line 
{
public:
    Point p1;
    Point p2;
    double slope;
    double yInter;

    Line(Point one, Point two) : p1(one), p2(two) 
    {
        slope = computeSlope(p1, p2);
        if (slope != INF)
            yInter = p1.y - slope * p1.x;
        else
            yInter = p1.x;
    }
    double computeSlope(Point p1, Point p2) 
    {
        if (fabs(p1.x - p2.x) < TOLERANCE)
            return INF;
        else
            return (p2.y - p1.y) / (p2.x - p1.x);
    }
    bool operator< (const Line & line) const 
    {
        if (fabs(slope - line.slope) > TOLERANCE)
            return slope < line.slope;
        else
            return yInter < line.yInter;
    }
};

void printPoints(vector<Point> collinear) 
{
    vector<Point>::iterator it;
    int count = 0;
    it = unique(collinear.begin(), collinear.end());
    for (vector<Point>::iterator itr = collinear.begin(); itr != it; itr++)
        count++;
    if (count > 3)
        for (vector<Point>::iterator itr = collinear.begin(); itr != it; itr++)
            cout << "(" << itr->x << "," << itr->y << ")\n";
}

int main() 
{
    vector<Point> points;
    vector<Line> lines;
    vector<Point> collinear;
    int numPoints;
    cout << "Enter the amount of points: ";
    cin >> numPoints;
    points.resize(numPoints);
    for (int i = 0; i < numPoints; i++) 
    {
        cout << "Enter the x and y coordinates for the " << i << "th point :";
        cin >> points[i].x >> points[i].y;
    }
    for (int i = 0; i < points.size(); i++)
        for (int j = i + 1; j < points.size(); j++) 
        {
            lines.emplace_back(points[i], points[j]);
        }
    sort(lines.begin(), lines.end());
    for (int i = 0; i < lines.size() - 1; i++) 
    {
        if (fabs(lines[i].slope - lines[i + 1].slope) < TOLERANCE &&
            fabs(lines[i].yInter - lines[i + 1].yInter) < TOLERANCE) 
        {
            collinear.push_back(lines[i].p1);
            collinear.push_back(lines[i].p2);
            collinear.push_back(lines[i + 1].p1);
            collinear.push_back(lines[i + 1].p2);
        } 
        else 
        {
            printPoints(collinear);
            collinear.clear();
        }
    }
    printPoints(collinear);
    return 0;
}