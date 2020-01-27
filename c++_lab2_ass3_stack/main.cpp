#include <iostream>

using namespace std;


class Stack
{
    int *stk;
    int tos, sizeOfStack;

public:
    Stack(int s = 5)
    {
        cout << "\ncalling constructor " << endl;
        tos =0;
        sizeOfStack=s;
        stk = new int[sizeOfStack];
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

    friend void viewContent (Stack s);

    Stack reverse_fn ()
    {
        Stack res ;
        int temp ;
        res.tos = tos;
        res.stk = new int [sizeOfStack];
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
};

    void viewContent (Stack s)
    {
        for (int i=0 ; i<s.tos ; i++)
            cout << s.stk[i] << endl;
    }




int main()
{
    Stack s1(7);
    s1.push(3);
    s1.push(5);
    s1.push(7);
    viewContent(s1);
    return 0;
}
