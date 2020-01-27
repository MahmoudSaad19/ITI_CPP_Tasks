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
        cout << "\ncalling empty constructor real = 0 and img=0 " << endl;
    }

    Complex (int v)
    {
        real=img=v;
        cout << "\ncalling 1 parameter constructor real = "<< v<<" and img = " << v << endl;
    }

    Complex (int r, int i)
    {
        real = r;
        img = i;
        cout << "\ncalling 2 parameter constructor real = "<< r<<" and img = " << i << endl;
    }

    Complex (Complex &c)
    {
        cout << "\ncalling  copy constructor " << endl;
        real = c.real;
        img  = c.img;
    }

    ~Complex ()
    {
        cout << "\ncalling destructor "<< endl;
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
};

Complex subComplex (Complex c1 , Complex c2)
{
    Complex res ;
    res.set_real(c1.get_real()-c2.get_real());
    res.set_img(c1.get_img()-c2.get_img());
    return res ;

}

class Stack
{
    int *stk;
    int tos, sizeOfStack;

public:
    Stack(int s = 5)
    {
        tos =0;
        sizeOfStack=s;
        stk = new int[sizeOfStack];
    }

    Stack (Stack &s)
    {
        cout << "\ncalling  copy constructor " << endl;
        tos = s.tos;
        sizeOfStack = s.sizeOfStack;
        stk = new int [sizeOfStack];
        for (int i=0 ; i<tos ; i++)
            stk[i]=s.stk[i];
    }

    ~Stack ()
    {
        cout << "\ncalling destructor "<< endl;
        delete []stk ;
    }

    int isFull ()
    {
        return tos ==sizeOfStack;
    }

    int isEmpty ()
    {
        return !tos;
    }

    void push (int v)
    {
        if (!isFull())
            stk[tos++]=v;
        else
            cout << "\n stack is full "<< endl;
    }

    int pop ()
    {
        if (!isEmpty())
            return stk[--tos];
        return -1 ;
    }

    int peak ()
    {
        if (!isEmpty())
            return stk[tos-1];
        return -1 ;
    }
};


int main()
{
    Complex c1 , c2(10,20), c3(3) ;
    c1 = c2.sumComplex(c3);

    return 0;
}
