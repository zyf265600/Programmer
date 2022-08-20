#include <iostream>
using namespace std;

class Cube
{

private:
    double m_H;
    double m_W;
    double m_L;
    double Area ;
    double Volume ;

public:
    void setH(double hight)
    {
        m_H = hight;
    }

    double getH()
    {
        return m_H;
    }

    void setW(double width)
    {
        m_W = width;
    }

    double getW()
    {
        return m_W;
    }

    void setL(double length)
    {

        m_L = length;
    }

    double getL()
    {
        return m_L;
    }

    double calcVolume()
    {
        Volume = m_H * m_W * m_L;
        // cout << "Volume: " << Volume << endl;
        return Volume;
    }

    double calcArea()
    {
        Area = ((m_H * m_W) + (m_W * m_L) + (m_L * m_H)) * 2;
        // cout << "Area: " << Area << endl;
        return Area;
    }

    bool CEqCube(Cube &c2)
    {
        if (calcVolume() == c2.calcVolume() && calcArea() == c2.calcArea())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

//全局函数判断
double EqCube(Cube &c1, Cube &c2) //引用方式传递不会拷贝数据
{
    if ((c1.calcVolume() == c2.calcVolume()) && (c1.calcArea() == c2.calcArea()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Cube c1;
    c1.setH(2);
    c1.setW(2);
    c1.setL(2);
    c1.calcVolume();
    c1.calcArea();

    Cube c2;
    c2.setH(1);
    c2.setW(2);
    c2.setL(4);
    c2.calcVolume();
    c2.calcArea();

    if (EqCube(c1, c2))
    {
        cout << "The Cubes are same!" << endl;
    }
    else
    {
        cout << "The Cubes are not same!" << endl;
    }

    if (c1.CEqCube(c2))
    {
        cout << "The Cubes are same!" << endl;
    }
    else
    {
        cout << "The Cubes are not same!" << endl;
    }

    return 0;
}