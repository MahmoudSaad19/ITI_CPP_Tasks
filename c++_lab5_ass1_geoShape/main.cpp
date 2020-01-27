#include <iostream>

using namespace std;
// this is the same class in lecture 5
class GeoShape
{
protected :
    int dim1;
    int dim2;

public :
    GeoShape( int d1=0 , int d2=0 )
    {
        dim1 = d1;
        dim2 = d2;
    }

    ~GeoShape() {}

    int getdim1 () { return dim1 ;}

    int getdim2 () { return dim2 ;}

    void setdim1 ( int d) { dim1 = d ;}

    void setdim2 ( int d) { dim2 = d ;}

};

class Rect : public GeoShape
{
public :
    Rect( int w , int e) : GeoShape(w,e) {}

    ~Rect() {}

    double cArea () { return dim1 *dim2 ;}
};

class Square : protected Rect
{
public :
    Square (int l) : Rect (l,l) {}

    ~Square(){}

    void setdim ( int d) { dim1 = dim2 = d ;}

    int getdim () { return dim1 ;}

    double cArea () { return Rect ::cArea() ;}
};

class Tri : public GeoShape
{
public :
    Tri(int w , int d) : GeoShape(w,d) {}

    ~Tri() {}

    double cArea () { return 0.5*dim1 *dim2 ;}
};

class Circle : public GeoShape
{
public:
    Circle(int r) : GeoShape(r,r) {}

    ~Circle() {}

    double cArea () { return 3.14*dim1 *dim2 ;}

    void setdim1 ( int d) { dim1 = dim2 = d ;}

    void setdim2 ( int d) { dim1 = dim2 = d ;}

};

int main()
{
    Rect r(10,15) ;
    Square s(20);
    Tri t(25,30);
    Circle c(35);

    cout << "Rectangle Area : 10 x 15 = ";
    cout << r.cArea() << endl ;
    cout << "Square Area : 20 x 20 = " ;
    cout << s.cArea() << endl ;
    cout << "Triangle Area : 0.5 x 25 x 30 = ";
    cout << t.cArea() << endl ;
    cout << "Circle Area : 3.14 x 35 x 35 = " ;
    cout << c.cArea() << endl ;

	return 0;
}
