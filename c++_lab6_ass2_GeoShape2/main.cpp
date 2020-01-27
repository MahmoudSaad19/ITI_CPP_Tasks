#include <iostream>

using namespace std;

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

    ~GeoShape()
    {
        //cout << "\t Destroy ^_^" << endl ;
    }

    int getdim1 () { return dim1 ;}

    int getdim2 () { return dim2 ;}

    void setdim1 ( int d) { dim1 = d ;}

    void setdim2 ( int d) { dim2 = d ;}

    virtual double cArea () =0;

};

class Rect : public GeoShape
{
public :
    Rect( int w , int e) : GeoShape(w,e) {}

    ~Rect() {}

    double cArea () { return dim1 *dim2 ;}
};

class Square : public Rect
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

double sumOfAreas (GeoShape ** g , int v)
{
    double sum =0;
    for (int i=0 ; i<v ; i++)
        sum+= g[i]->cArea();
    return sum;
}
int main()
{
    Rect arr1[2]={Rect(10,15) , Rect(20,25) };
    Square arr2[3]={Square(30) ,Square(35) ,Square(40) };
    Tri arr3[2] ={Tri(40,50) ,Tri(55,60) };
    Circle arr4[3]={Circle(65) , Circle(70) , Circle(75)};

    GeoShape* Arr[10] ={arr1 ,&arr1[1] ,arr2 ,&arr2[1] ,&arr2[2],
    arr3 , &arr3[1] ,arr4 ,&arr4[1] ,&arr4[2]};

    cout << sumOfAreas(Arr,10);

	return 0;
}
