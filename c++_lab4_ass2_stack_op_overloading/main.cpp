#include <iostream>

using namespace std;


class Stack
{
    int *stk;
    int tos, sizeOfStack;

public:
    Stack(int s = 5)
    {
        //cout << "\ncalling constructor " << endl;
        tos =0;
        sizeOfStack=s;
        stk = new int[sizeOfStack];
    }

    Stack ( Stack &s)
    {
        //cout << "\ncalling  copy constructor " << endl;
        tos = s.tos;
        sizeOfStack = s.sizeOfStack;
        stk = new int [sizeOfStack];
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

    Stack & operator = (Stack & s)
    {
        delete [] stk;
        tos=s.tos;
        sizeOfStack = s.sizeOfStack;
        stk = new int [sizeOfStack] ;
        for (int i=0 ; i<tos ; i++)
            stk[i] = s.stk[i] ;
        return *this ;
    }

    int operator == (Stack & s)
    {
        if (tos == s.tos && sizeOfStack == s.sizeOfStack)
        {
            for (int i=0 ; i<tos ; i++)
            {
                if (stk[i] == s.stk[i])
                    continue;
                else
                    return 0;
            }
            return 1;
        }
        return 0;
    }

    Stack operator + (Stack & s)
    {
        Stack st;
        st.tos = s.tos + tos;
        st.sizeOfStack = sizeOfStack+s.sizeOfStack ;
        st.stk = new int [st.sizeOfStack];
        for (int i=0 ; i<tos ; i++ )
            st.stk[i] = stk[i];
        for (int i=0 ; i<s.tos ; i++ )
            st.stk[i+tos] = s.stk[i] ;
        return st ;
    }
    friend void viewContent( Stack &s2);
};

   void viewContent( Stack &s2)
   {
        cout << "View Content:" << endl;
        for(int i=0;i<s2.tos;i++)
            cout << s2.stk[i] << "\t";
        cout << endl;
    }




int main()
{
    Stack s1(7) , s2 ,s3 ,s4(0);
    s1.push(3);
    s1.push(5);
    s1.push(7);
    viewContent(s1);
    s2.push(1);
    s2.push(2);
    s2.push(4);
    s2.push(8);
    viewContent(s2);

    s3 = s1;
    viewContent(s3);
    int r = s2==s1;
    cout << "r = " << r << endl ;
    s4=s2+s1;
    viewContent(s4);
    return 0;
}
