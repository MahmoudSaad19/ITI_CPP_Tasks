#include <iostream>
#include "graphics.h"

using namespace std;
/*
this assignment is a composition relation between
point and shapes( rect,tri ,circle ) and shape class
*/
class Point
{
    int x,y;
public:

    Point()
    {
        x=y=0;
    }
    Point(int _x, int _y)
    {
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
    }
    ~Rect()
    {

    }
    Rect(int x1 , int y1 , int x2 , int y2 , int c) :UL(x1,y1) , LR(x2,y2)
    {
            color = c;
    }

    Rect(Point p1 , Point p2 , int c) :UL(p1),LR(p2)
    {
        color = c;
    }

    void draw()
    {
        setcolor(color);
        rectangle(UL.getX(),UL.getY() , LR.getX() , LR.getY());
    }
};

class Circle
{
public:
    Point c;
    int r;
    int color;

    Circle()
    {
        color =r= 0;
    }
    ~Circle()
    {

    }
    Circle(int x1 , int y1 , int x , int col) :c(x1,y1)
    {
            color = col;
            r=x;
    }

    Circle(Point p1 , int l , int c) :c(p1)
    {
        color = c;
        r=l;
    }

    void draw()
    {
        setcolor(color);
        circle(c.getX(),c.getY(),r);
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

class Shape
{
    Point p1 ,p2 ,p3 ,p4 ,p5 ,p6 ,p7 ,p8 ,p9 ,t ,b ,r;
    int color , radius;
public:
    // line constructor
    Shape(int x1 , int y1 , int x2 , int y2 , int c)

        :p1(x1,y1) , p2(x2,y2)
    {
            color = c;
    }

    // triangle constructor
    Shape(int x1 , int y1 , int x2 , int y2 ,int x3 , int y3 , int c)

        :t(x1,y1) , b(x2,y2) , r(x3,y3)
    {
            color = c;
    }
    // circle constructor
    Shape(int x1 , int y1 , int r ,int c)

        :p3(x1,y1)
    {
            radius = r;
            color = c;
    }

    void drawLines()
    {

        line(p1.getX(),p1.getY() , p2.getX() , p2.getY());
    }
    void drawTri()
    {
        setcolor(color);
        line(t.getX(),t.getY(),b.getX(),b.getY());
        line(b.getX(),b.getY(),r.getX(),r.getY());
        line(r.getX(),r.getY(),t.getX(),t.getY());
    }

    void drawCircles()
    {
        setcolor(color);
        circle(p3.getX(),p3.getY() , radius );
    }
    void drawRects()
    {
        setcolor(color);
        rectangle(p1.getX(),p1.getY() , p2.getX() , p2.getY());
    }
};


int main()
{
    initgraph();
    Shape s1(350 , 100 , 40 ,15);
    Shape s2(350 , 204 , 80 ,2);
    Shape s3(330,100 , 310 ,204 ,7);
    Shape s4(370,100 , 390 ,204 ,7);
    Shape s5(330,240,373,260,7);
    Shape s6(290,260,413,300,7);
    Shape s7(444,535 , 456 ,560 ,434 , 560 ,0);

    s1.drawCircles();
    s2.drawCircles();
    s3.drawLines();
    s4.drawLines();
    s5.drawRects();
    s6.drawRects();
    s7.drawTri();
}
