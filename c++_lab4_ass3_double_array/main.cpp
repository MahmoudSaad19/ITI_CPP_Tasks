#include <iostream>

using namespace std;

class doubleArray
{
private:
    double *arr;
    int size;

public:
    doubleArray(int n=10)
    {
        size = n;
        arr = new double [size];
    }

    ~doubleArray()
    {
        delete []arr;
    }

    doubleArray(doubleArray &d)
    {
        size = d.size;
        for (int i = 0; i<size; i++)
			arr[i] = d.arr[i];
    }


    int getValue(int index)
    {
        if ((index >= 0)&&(index < size))
            return arr[index];
    }

    int setValue(int index, int value)
    {
        if ((index >= 0)&&(index < size))
            arr[index] = value;
    }

    double  operator [] ( const int index)
    {
        if ((index >= 0) && (index < size))
            return arr[index];
    }

    int  operator == ( doubleArray &a)
    {
        for(int i=0;i<size;i++)
        {
            if(arr[i] != a.arr[i])
                return 0;
        }
        return 1;
    }

    doubleArray&  operator = (doubleArray & m)
    {
        for(int i = 0; i < size; i++)
        {
            arr[i] = m[i];
        }

        return *this;
    }

    doubleArray& operator + (doubleArray & m)
    {
        for(int i = 0; i < size; i++)
        {
            arr[i] = arr[i]+m[i];
        }

        return *this;
    }
};

int main()
{
    doubleArray m(3), n(3) , k(5) , a;

    m.setValue(0,1);
    m.setValue(1,2);
    m.setValue(2,3);

    cout<<m.getValue(0)<<endl;
    cout<<m.getValue(1)<<endl;
    cout<<m.getValue(2)<<endl;

    n.setValue(0,1);
    n.setValue(1,2);
    n.setValue(2,3);
    cout<<n.getValue(0)<<endl;
    cout<<n.getValue(1)<<endl;
    cout<<n.getValue(2)<<endl;

    (n == m)? cout<<"True"<<endl : cout<<"false"<<endl ;

    k = n;

    for(int i =0;i<3;i++)
        cout<<k[i]<<endl;

    a = n+m;

    for(int i =0;i<3;i++)
        cout<<n[i]<<endl;
}
