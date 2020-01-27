#include <iostream>

using namespace std;

template <class t>
class Stack
{
    t *stk;
    int tos, sizeOfStack;

public:
    Stack(int s = 5)
    {
        //cout << "\ncalling constructor " << endl;
        tos =0;
        sizeOfStack=s;
        stk = new t[sizeOfStack];
    }

    Stack ( Stack &s)
    {
        //cout << "\ncalling  copy constructor " << endl;
        tos = s.tos;
        sizeOfStack = s.sizeOfStack;
        stk = new t[sizeOfStack];
        for (int i=0 ; i<tos ; i++)
            stk[i]=s.stk[i];
    }

    ~Stack ()
    {
        //cout << "\ncalling destructor "<< endl;
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

    void push (t v)
    {
        if (!isFull())
            stk[tos++]=v;
        else
            cout << "\n stack is full "<< endl;
    }

    t pop ()
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

    Stack reverse_fn ()
    {
        Stack res ;
        int temp ;
        res.tos = tos;
        res.stk = new t [sizeOfStack];
        for (int i=0 ; i<res.tos; i++)
            res.stk[i]=stk[i];
        for (int i=0 ; i<tos ; i++)
        {
            temp = res.stk[i] ;
            res.stk[i] = res.stk[tos-1] ;
            res.stk[tos-1] = res.stk[i] ;
        }
        return res ;
    }

    void viewContent( )
   {
        cout << "View Content:" << endl;
        for(int i=0;i<tos;i++)
            cout << stk[i] << endl;
        cout << endl;
    }
};





int main()
{
    Stack <int> s2(7) ;
    Stack <double> s1;
    s1.push(3.2);
    s1.push(5.5);
    s1.push(7.7);
    s1.viewContent();
    s2.push(1);
    s2.push(2);
    s2.push(4);
    s2.push(8);
    s2.viewContent();

    return 0;
}
