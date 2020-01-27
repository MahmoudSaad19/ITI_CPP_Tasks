#include<iostream>

using namespace std;

class IndiaBix
{
    int x;
    float y;

    public:/*
    IndiaBix(int z )
    {
        x = z;
    }*/
    IndiaBix(int p =1, int q =10 )
    {
        x = p += 2;
        y = q * 1.0f;
    }
    void SetValue(int &y, float z)
    {
        x = y;
        y = (int)z;
    }
    void Display(void)
    {
        cout<< x;
    }
};
int main()
{
    int x = 10, y = 20;
    int *ptr = &x;
    int &ref = y;

    (*ptr)++;
     ref++;

    cout<< x << " " << y;
    return 0;
}
