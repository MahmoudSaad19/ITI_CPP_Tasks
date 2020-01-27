#include <iostream>

using namespace std;
/*
the assignment is making class complex with 3 functions + constructor + destructor :
1-print
2-add
3-sum
*/
class Complex
{
    int real ;
    int img;

public :

    Complex ()
    {
        real=img=0;
        //cout << "\ncalling empty constructor real = 0 and img=0 " << endl;
    }

    Complex (int v)
    {
        real=img=v;
        //cout << "\ncalling 1 parameter constructor real = "<< v<<" and img = " << v << endl;
    }

    Complex (int r, int i)
    {
        real = r;
        img = i;
        //cout << "\ncalling 2 parameter constructor real = "<< r<<" and img = " << i << endl;
    }

    ~Complex ()
    {
        //cout << "\ncalling destructor "<< endl;
    }

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

    Complex operator + (const Complex & c)
    {
        Complex result (c.real +real , c.img + img);
        return result;
    }

    Complex operator - (Complex & c)
    {
        Complex res (real - c.real , img - c.img);
        return res;
    }

    Complex operator + (int x)
    {
        Complex result (real + x,img);
        return result;
    }

    Complex operator - (int x)
    {
        Complex result (real - x,img);
        return result;
    }

    Complex operator -= (Complex & c)
    {
        real -= c.get_real();
        img -= c.get_img();
        return *this;
    }

    Complex operator += (Complex & c)
    {
        real += c.get_real();
        img += c.get_img();
        return *this;
    }

    Complex operator -= (int x)
    {
        real -= x;
        return *this;
    }

    Complex operator += (int x)
    {
        real += x;
        return *this;
    }

    Complex operator ++()
    {
        real++;
        return *this;
    }

    Complex operator ++(int)
    {
        Complex temp (real,img) ;
        real++;
        return temp;
    }

    int operator ==(Complex & c)
    {
        return (real == c.real ) && (img == c.img);
    }

    int operator !=(Complex & c)
    {
        return (real != c.real ) && (img != c.img);
    }

    int operator >(Complex & c)
    {
        return (real > c.real ) ;
    }

    int operator <(Complex & c)
    {
        return (real < c.real ) ;
    }

    int operator >=(Complex & c)
    {
        return (real >= c.real ) ;
    }

    int operator <=(Complex & c)
    {
        return (real <= c.real ) ;
    }

    operator int ()
    {
        return real ;
    }

};

Complex operator + (int x , Complex & c)
{
    return c+x;
}

Complex operator - (int x , Complex & c)
{
    Complex res (x-c.get_real() , c.get_img());
    return res;
}



int main()
{
    Complex c1(3,4) , c2(5,6), c3 ;

    c3 =c1 +c2;
    c3.print();

    c3 =c1 -c2;
    c3.print();

    c3 =c1 +5;
    c3.print();

    c3 =c1 -5;
    c3.print();

    c3 =7-c2;
    c3.print();

    c3 =7 +c2;
    c3.print();

    c3 += c2;
    c3.print();

    c3 -=c2;
    c3.print();

    c3 +=7;
    c3.print();

    c3 -=7;
    c3.print();

    c3 =c2++;
    c3.print();

    ++c3;
    c3.print();

    int R = (int) c3;
    cout << R ;

    return 0;
}
