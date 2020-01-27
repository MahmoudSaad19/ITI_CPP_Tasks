#include <iostream>
#include "graphics.h"

using namespace std;

class Point
{
    int x,y;
public:

    Point()
    {
        x=y=0;
                cout<<"p ctr"<<endl;

    }
    Point(int _x, int _y)
    {
        cout<<"p ctr"<<endl;
        x=_x;
        y=_y;
    }
    ~Point()
    {
    }
    Point(Point & p)
    {
        x= p.x;
        y = p.y;
    }
    void show()
    {
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    void setX(int n)
    {
        x = n;
    }
    void setY(int s)
    {
        y= s;
    }
};


class Rect
{
    Point UL;
    Point LR;
    int color;
public:
    Rect()
    {
        color = 0;
                cout<<"rect ctr"<<endl;

    }
    ~Rect()
    {

    }
    Rect(int x1 , int y1 , int x2 , int y2 , int c) :UL(x1,y1) , LR(x2,y2)
    {
            color = c;
                            cout<<"rect ctr"<<endl;

    }

    Rect(Point p1 , Point p2 , int c) :UL(p1),LR(p2)
    {
        color = c;
                        cout<<"rect ctr"<<endl;

    }

    void draw()
    {
        setcolor(color);
        rectangle(UL.getX(),UL.getY() , LR.getX() , LR.getY());
    }
};

class Line
{
    Point L;
    Point R;
    int color;
public:
    Line()
    {
        color = 0;
    }
    ~Line()
    {

    }
    Line(int x1 , int y1 , int x2 , int y2 , int c) :L(x1,y1) , R(x2,y2)
    {
            color = c;
    }


    Line(Point p1 , Point p2 , int c) :L(p1),R(p2)
    {
        color = c;
    }
    void draw()
    {
        setcolor(color);
        line(L.getX() , L.getY() , R.getX() , R.getY());
    }
};

class Triangle
{
    Point top;
    Point left;
    Point right;
    int color;
public:
    Triangle()
    {
        color = 0;
    }
    ~Triangle()
    {

    }

    Triangle(int x1 , int y1 , int x2 , int y2 ,int x3 , int y3 , int c)
        :top(x1,y1) , left(x2,y2) , right(x3,y3)
    {
            color = c;
    }

    void draw()
    {
        setcolor(color);
        line(top.getX(), top.getY() , right.getX() , right.getY());
        line(top.getX(), top.getY() , left.getX() , left.getY());
        line(right.getX() , right.getY() , left.getX() , left.getY());

    }


};


int main()
{
    initgraph();
    //Triangle t(417,114,533,326,301,326,7);
    //t.draw();

    Rect r(10,70,950,470,7);
    //r.draw();

}
