#include "circle.h"

//设置半径
void Circle::setRadius(int rad)
{
    r = rad;
}
//获取半径
int Circle::getRadius()
{
    return radius;
}

//设置圆心
void Circle::setCenter(Point p)
{
    center = p;
}

//获取圆心
Point Circle::getCenter()
{
    return center;
}
