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
    Tri():p1(),p2(),p3(),Shape(0){}
    Tri(int x1,int y1,int x2,int y2,int x3,int y3,int c)
    :p1(x1,y1),p2(x2,y2),p3(x3,y3),Shape(c){}

      void setTri(int x1,int y1,int x2,int y2,int x3,int y3,int c)
    {
        p1.setX(x1) ; p1.setY(y1);
        p2.setX(x2) ; p2.setY(y2);
        p3.setX(x3) ; p3.setY(y3);
        color = c;
    }
    void draw()
    {
        setcolor(color);
        line(p1.getX(),p1.getY(),p2.getX(),p2.getY());
        line(p2.getX(),p2.getY(),p3.getX(),p3.getY());
        line(p3.getX(),p3.getY(),p1.getX(),p1.getY());
    }
};

class Picture{
    Rect *rArr;
    Circle *cArr;
    Line *lArr;
    Tri *tArr;
    int Rnum , Cnum , Lnum , Tnum;
    
public:
    Picture(){
        Rnum =0; rArr = NULL;
    }
    Picture(Rect *prect , int r , Circle *pcircle , int c , Line *pline , int l , Tri *ptri , int t){
        rArr = prect;
        cArr = pcircle;
        lArr = pline;
        tArr = ptri;
        Rnum = r;
        Cnum = c;
        Lnum = l;
        Tnum = t;
    }
    void setRect(Rect *prect,int r){
        rArr = prect;
        Rnum = r;
    }
    void setCircle(Circle *pcircle,int c){
        cArr = pcircle;
        Cnum = c;
    }
    void setLine(Line *pline,int l){
        lArr = pline;
        Lnum = l;
    }
    void setTri(Tri *ptri,int t){
        tArr = ptri;
        Tnum = t;
    }
    void paint(){
        for(int i=0;i<Rnum;i++)
                rArr[i].draw();

        for(int i=0;i<Cnum;i++)
                cArr[i].draw();

        for(int i=0;i<Lnum;i++)
                lArr[i].draw();

        for(int i=0;i<Tnum;i++)
                tArr[i].draw();
    }
};

int main()
{
    initgraph();
    Picture p;

    Circle *Carr;
    Carr = new Circle[2];
    Carr[0].setCircle(350 , 100 , 40 ,7);
    Carr[1].setCircle(350 , 204 , 80 ,6);

    Line *Larr;
    Larr = new Line[2];
    Larr[0].setLine(330,100 , 310 ,204 ,7);
    Larr[1].setLine(370,100 , 390 ,204 ,7);

    Rect *Rarr;
    Rarr = new Rect[2];
    Rarr[0].setRect(330,240,373,260,7);
    Rarr[1].setRect(290,260,413,300,7);

    Tri *Tarr;
    Tarr = new Tri[1];
    Tarr[0].setTri(444,535 , 456 ,560 ,434 , 560 ,16);

    p.setCircle(Carr,2);
    p.setLine(Larr,2);
    p.setRect(Rarr,2);
    p.setTri(Tarr,1);
    p.paint();

    delete []Carr;
    delete []Larr;
    delete []Rarr;
    delete []Tarr;
}
