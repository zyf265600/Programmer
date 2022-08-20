#include <iostream>
#include <math.h>
#include "point.h"
#include "circle.h"
using namespace std;


//判断点和圆的关系
void rel_cirlce_point(Circle &c, Point &p)
{

    int Square_radius = c.getRadius() * c.getRadius();
    int Square_points_distance = pow((p.getX() - c.getCenter().getX()), 2) + pow((p.getY() - c.getCenter().getY()), 2);

    // cout << Square_radius << endl;
    // cout << Square_points_distance << endl;

    if (Square_radius == Square_points_distance)
    {
        cout << "点在圆上！" << endl;
    }
    else if (Square_radius > Square_points_distance)
    {
        cout << "点在圆内！" << endl;
    }
    else
    {
        cout << "点在圆外！" << endl;
    }
}

int main()
{
    Circle c1;
    Point p1;

    p1.setX(10);
    p1.setY(0);
    c1.setCenter(p1);
    c1.setRadius(10);

    Point p2;
    p2.setX(10);
    p2.setY(9);

    rel_cirlce_point(c1, p2);

    return 0;
}