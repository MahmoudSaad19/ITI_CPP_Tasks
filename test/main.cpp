#include<iostream>
using namespace std;

class A
{
protected:
  int x;
public:
    A(){ cout << "A ctr" << endl ;}
        virtual ~A(){ cout << "A dest" << endl ;}

  void setX(int i) {x = i;}
  virtual void print() { cout << x << " A" << endl; }
};

class B:  public A
{
public:

  B()  { setX(10);
  cout << "B ctr" << endl ; }
    void print() { cout << x << " B" << endl; }
    void printd() { cout << x*2 << " dB" << endl; }

          ~B(){ cout << "B dest" << endl ;}

};

class C:  virtual public A
{
public:
  C()  { setX(20);
  cout << "C ctr" << endl ;}
          ~C(){ cout << "C dest" << endl ;}

};

class D: public B {
    public:

    D(){cout << "D ctr" << endl ;}
    ~D(){ cout << "D dest" << endl ;}


};

int main()
{

    A *baseptr = new B() ;
    baseptr->print();

    delete baseptr;

    //D d ;
//    d.print();

    return 0;
}
