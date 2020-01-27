#include <iostream>

using namespace std;
/*
the assignment is making struct complex with 3 funcions  :
1-print
2-add
3-sum
*/
struct Complex
{
private :

    int real ;
    int img;

public :

    void set_real ( int r)
    {     real =r;    }
    int get_real ( )
    {  return real ;  }
    void set_img ( int i)
    {     img =i;    }
    int get_img ( )
    {  return img ;  }

    void print ()
    {
        if(img > 0)
            if (real == 0)
            cout << "complex number = " << img <<"i" << endl;
            else
            cout << "complex number = " << real <<"+" << img <<"i" << endl;
        else if (img <0)
            if (real == 0)
            cout << "complex number = " << img <<"i" << endl;
            else
            cout << "complex number = " << real << img <<"i" <<endl;
        else if (img ==0)
            cout << "complex number = " << real << endl;

    }

    Complex sumComplex (Complex c)
    {
        Complex res ;
        res.set_real(real + c.get_real() );;
        res.set_img(img+ c.get_img());
        return res ;
    }
};

Complex subComplex (Complex c1 , Complex c2)
{
    Complex res ;
    res.set_real(c1.get_real()-c2.get_real());
    res.set_img(c1.get_img()-c2.get_img());
    return res ;

}

int main()
{
    Complex c1 , c2, c3 ,c4 ,c5 ,c6;

    cout << "\nc1 = " << endl;
    c1.set_real(0);
    c1.set_img(-1);
    c1.print();

    cout << "\nc2 = " << endl;
    c2.set_real(4);
    c2.set_img(-7);
    c2.print();

    cout << "\nc3 = " << endl;
    c3.set_real(0);
    c3.set_img(7);
    c3.print();

    cout << "\nc4 = " << endl;
    c4.set_real(4);
    c4.set_img(0);
    c4.print();

    cout << "\nc5 = " << endl;
    c5.set_real(0);
    c5.set_img(0);
    c5.print();

    cout << "\nc6 = " << endl;
    c6.set_real(0);
    c6.set_img(-7);
    c6.print();

    cout << "\n\n sum = \n\tc1=c2+c3 " << endl;
    c1= c2.sumComplex(c3);
    c1.print();

    cout << "\n\n sub = \n\tc4=c5+c6" << endl;
    c4= subComplex(c5,c6);
    c4.print();
    return 0;
}
