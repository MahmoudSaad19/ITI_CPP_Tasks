#include <iostream>

using namespace std;


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

    friend void viewContent (Stack s);
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
    cout << " pop : "<<s1.pop() << endl;
    return 0;
}
