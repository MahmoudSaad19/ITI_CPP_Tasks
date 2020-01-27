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

class Shape {
protected:
    int color;
public:
    Shape(int c)
    {
        color = c;
    }
    void setShapeColor(int c){
        color = c;
    }
    int getShapeColor(){
        return color;
    }
    virtual void draw () =0 ;
};


class Rect:public Shape{
Point ul,rl;
public :
    Rect()
    :ul(),rl(),Shape(0){}
    Rect(int x1,int y1,int x2, int y2, int c)
    :ul(x1,y1),rl(x2,y2),Shape(c){}

    void draw()
    {
        setcolor(color);
        rectangle(ul.getX(),ul.getY() , rl.getX() , rl.getY());
    }
    void setRect(int x1,int y1,int x2, int y2, int c)
    {
        ul.setX(x1); ul.setY(y1);
        rl.setX(x2); rl.setY(y2);
        color = c;
    }

};

class Circle:public Shape{
Point cr;
int rad;
public :
    Circle()
    :cr(),Shape(0){}
    Circle(int x,int y,int c,int r)
    :cr(x,y),Shape(c){
        rad = r;
    }
    void draw()
    {
        setcolor(color);
        circle(cr.getX(),cr.getY() , rad );
    }
    void setCircle(int x , int y , int r , int c)
    {
        cr.setX(x); cr.setY(y);
        rad = r;
        color = c;
    }
};

class Line:public Shape{
Point f,l;
public :
    Line()
    :f(),l(),Shape(0){}
    Line(int x1,int y1,int x2,int y2,int c)
    :f(x1,y1),l(x2,y2),Shape(c){}
    void draw()
    {
        setcolor(color);
        line(f.getX(),f.getY() , l.getX() , l.getY());
    }
    void setLine(int x1 , int y1 , int x2 , int y2 , int c)
    {
        f.setX(x1) ; f.setY(y1);
        l.setX(x2) ; l.setY(y2);
        color = c;
    }
};

class Tri:public Shape{
Point p1,p2,p3;
public :
    Tri()
    :p1(),p2(),p3(),Shape(0){}
    Tri(int x1,int y1,int x2,int y2,int x3,int y3,int c)
    :p1(x1,y1),p2(x2,y2),p3(x3,y3),Shape(c){}
    void draw()
    {
        setcolor(color);
        line(p1.getX(),p1.getY(),p2.getX(),p2.getY());
        line(p2.getX(),p2.getY(),p3.getX(),p3.getY());
        line(p3.getX(),p3.getY(),p1.getX(),p1.getY());
    }

    void setTri(int x1,int y1,int x2,int y2,int x3,int y3,int c)
    {
        p1.setX(x1) ; p1.setY(y1);
        p2.setX(x2) ; p2.setY(y2);
        p3.setX(x3) ; p3.setY(y3);
        color = c;
    }

};

class Picture{
    Shape ** sarr;
    int arr_counter ;
public:
    Picture(){
        arr_counter =0; sarr = NULL;
    }
    Picture(Shape ** s , int a ){
        sarr = s;
        arr_counter = a;
    }
    void setShapes(Shape ** s , int a ){
        sarr = s;
        arr_counter = a;
    }

    void paint(){
        for(int i=0;i<arr_counter;i++)
                sarr[i]->draw();
    }

};

int main()
{
    initgraph();
    Picture p;

    Circle Carr[2];
    Carr[0].setCircle(350 , 100 , 40 ,6);
    Carr[1].setCircle(350 , 204 , 80 ,6);

    Line Larr[2];
    Larr[0].setLine(330,100 , 310 ,204 ,7);
    Larr[1].setLine(370,100 , 390 ,204 ,7);

    Rect Rarr[2];
    Rarr[0].setRect(330,240,373,260,7);
    Rarr[1].setRect(290,260,413,300,7);

    Tri Tarr[1];
    Tarr[0].setTri(444,535 , 456 ,560 ,434 , 560 ,7);

    Shape *arr[7] = {Carr,&Carr[1],Larr,&Larr[1],Rarr,&Rarr[1],Tarr};
    p.setShapes(arr,7);
    p.paint();
}
