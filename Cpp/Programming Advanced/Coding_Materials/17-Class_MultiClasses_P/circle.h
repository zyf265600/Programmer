#pragma once //防止头文件重复包含
#include <iostream>
#include "point.h"
using namespace std;

//圆类
class Circle
{
private:
    int radius;
    int &r = radius;
    Point center;

public:
    //设置半径
    void setRadius(int rad);
    
    //获取半径
    int getRadius();

    //设置圆心
    void setCenter(Point p);

    //获取圆心
    Point getCenter();
};