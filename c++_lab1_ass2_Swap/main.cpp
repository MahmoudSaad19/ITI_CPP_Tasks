#include <iostream>

using namespace std;
/*
Assignment is making 3 swap functions : by value , address , refrence 
*/
 void swap_by_value (int a,int b)
 {
     int t;
     t=b;
     b=a;
     a=t;
 }
  void swap_by_add (int *a,int *b)
 {
     int t;
     t=*b;
     *b=*a;
     *a=t;
 }
  void swap_by_ref (int &a,int &b)
 {
     int t;
     t=b;
     b=a;
     a=t;
 }

int main()
{
    int x , z;
    x=6 , z= 4 ;
    cout << "x = 6 , z= 4" << endl;

    cout << "\ncalling swap_by_value" << endl;
    swap_by_value(x,z);
    cout << "x = " << x << " , z = " <<z << endl;

    cout << "\ncalling swap_by_add" << endl;
    swap_by_add(&x,&z);
    cout << "x = " << x<< ", z = " <<z << endl;

    cout << "\ncalling swap_by_ref" << endl;
    swap_by_ref(x,z);
    cout << "x = " << x<< ", z = " <<z << endl;
    return 0;
}
