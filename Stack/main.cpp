#include <iostream>

using namespace std;
/*
this class defines the behavior of stack which is a part of memory
it works as filo first in last out
*/
class Stack
{
    int *stk, sSize, tos ;

public:

    Stack(int s=5)
    {
        sSize = s;
        tos=0;
        stk = new int [sSize];
    }

    ~Stack()
    {
        delete []stk;
    }

    int isFull()
    {
        return tos == sSize ;
    }

    int isEmpty()
    {
        return !tos ;
    }

    void viewContent ()
    {
        int t = tos;
        if (t == 0)
            cout << "Stack is Empty" << endl ;
        else
        {
            cout  << "Stack content : " <<endl ;
            for (int i=0 ; i<tos ; i++)
                cout << i+1 << ") " << stk[i] << endl ;
        }
    }

    void push (int val)
    {
        if(!isFull())
        {
            stk[tos++]=val;
            cout << "Pushing : " << val << " to the stack ..." << endl ;
        }
        else
            cout << "Stack is full , You can't push any more items ." << endl ;
    }

    void pop()
    {
        if (!isEmpty())
            cout << stk[--tos] << " is popped from the stack." << endl ;
        else
            cout << "Stack is Empty." << endl ;
    }

    void peak()
    {
        if (!isEmpty())
            cout << stk[tos-1] << " is the last item entered the stack." << endl ;
        else
            cout << "Stack is Empty." << endl ;
    }

};

int main()
{
    Stack s;
    s.peak();
    s.pop();
    s.viewContent();
    cout << "Hello world!" << endl;
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(2);
    s.push(0);
    s.pop();
    s.push(8);
    s.push(11);
    s.viewContent();
    return 0;
}
