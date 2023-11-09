#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Point//定义一个点类
{
public:
    //设置x的值
    void setX(int x)
    {
        m_X = x;
    }
    //获取x
    int getX()
    {
        return m_X;
    }
    //设置y的值
        void setY(int y)
    {
        m_Y = y;
    }
    //获取y
    int getY()
    {
        return m_Y;
    }

private:
    int m_X;
    int m_Y;
};


class Circle
{
public:
    //设置半径
    void setR(int r)
    {
        m_R = r;
    }
    //获取半径
    int getR()
    {
        return m_R;
    }
    //设置圆心
    void setCenter(Point center)
    {
        m_Center = center;
    }
    //获取圆心
    Point getCenter()
    {
        return m_Center;
    }

private:
    int m_R;//半径
    
    Point m_Center;//圆心
                   //类的嵌套
};

//判断点和圆的关系
void isInCircle(Circle &c, Point &p)
{
     
    //计算两点之间距离的平方
    int dSqrt =
    pow((c.getCenter().getX() - p.getX()), 2) + 
    pow((c.getCenter().getY() - p.getY()), 2);

    //计算半径的平方
    int rSqrt = pow(c.getR(), 2);

    if(dSqrt == rSqrt)
    {
        cout << "点在圆上" << endl;
    }
    else if(dSqrt > rSqrt)
    {
        cout << "点在圆外" << endl;
    }
    else
        cout << "点在圆内" << endl;    
}

int main()
{
    Circle c;
    
    c.setR(10);
    
    //创建(10,10)的圆心
    Point center;
    center.setX(10);
    center.setY(10);
    c.setCenter(center);

    //创建点
    Point p;
    p.setX(10);
    p.setY(11);

    isInCircle(c,p);

    return 0;
}