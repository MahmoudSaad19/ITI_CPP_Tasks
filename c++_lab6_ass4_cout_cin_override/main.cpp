#include <iostream>

using namespace std;

class Complex
{
public :

    int real;
    int img;

    Complex ()
    {
        real = img = 0;
    }

    Complex (int x , int y)
    {
        real = x;
        img = y ;
    }

};


ostream &operator<<(ostream &output,const Complex &obj)
{
    output<<"Complex number = "<<obj.real<<" + "<<obj.img<< "i" <<endl;
    return output;
}

istream &operator>>(istream &input,Complex &obj)
{
    input>>obj.real>>obj.img;
    return input;
}

int main() {

  cout<<"Enter complex number real and imaginary parts : "<<endl;
  Complex c;
  cin>>c;
  cout<<c;

   return 0;
}

