#include "point.h"

//只写函数实现
//因为都是成员函数，必须加 Point:: 告诉是 Point 作用域下的成员函数

//设置 x 坐标
void Point::setX(int x_cod)
{
    this->x_cod = x_cod;
}
//获取 x 坐标
int Point::getX()
{
    return x_cod;
}

//设置 y 坐标
void Point::setY(int y_cod)
{
    this->y_cod = y_cod;
}
//获取 y 坐标
int Point::getY()
{
    return y_cod;
}