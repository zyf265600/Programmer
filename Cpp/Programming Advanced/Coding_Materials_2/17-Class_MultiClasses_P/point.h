#pragma once //防止头文件重复包含
#include <iostream>
using namespace std;

//点类
class Point
{
private:
    int x_cod;
    int y_cod;

public:
    //设置 x 坐标
    void setX(int x_cod);

    //获取 x 坐标
    int getX();

    //设置 y 坐标
    void setY(int y_cod);
    
    //获取 y 坐标
    int getY();
};