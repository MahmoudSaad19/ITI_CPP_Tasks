#include <iostream>



#include <iostream>


using namespace std;

class stack
{
public:
    int *stk;
    int tos;
    int  size;
public:
    stack(int L = 0){
        //cout << "Calling Constructor\n";
        tos = 0;
        size = L;
        stk = new int[size];
    }
    stack(const stack &old_stack)
    {
        tos = old_stack.tos;
        size = old_stack.size;
        stk = new int [size];
        for(int i=0;i<tos;i++)
            stk[i] = old_stack.stk[i];
    }
    ~stack(){
        //cout << "Calling Destructor\n";
        delete []stk;
    }

    int isFull(){
        return (tos == size);
    }
    int isEmpty(){
        return (tos == 0);
    }
    void push(int n){
        if(!isFull())
            stk[tos++] = n;
        else
            cout << "Stack is full\n";
    }
    void pop(){
        if(!isEmpty())
            cout << "POP " << stk[--tos] <<endl;
        else
            cout <<"Empty Stack"<<endl;
    }
    void peak(){
        if(!isEmpty())
            cout << "Current Peak " << stk[tos-1] <<endl;
        else
            cout <<"Empty Stack\n";
    }
    stack & operator = (const stack &s){
        delete []stk;
        tos = s.tos;
        size = s.size;
        stk = new int[size];
        for(int i=0;i<tos;i++)
            stk[i] = s.stk[i];
        return *this;
    }

    stack operator + (const stack &s){
        int Lsize = size + s.size;
        stack result(Lsize);
        result.tos = tos + s.tos;
        for(int i=0;i<size;i++)
            result.stk[i] = stk[i];
        int k = size;
        for(int j=0;k<Lsize;k++,j++)
            result.stk[k] = s.stk[j];
        return result;
    }
    int operator == (const stack &s){
        int count = 0;
        if((size == s.size) && (tos == s.tos))
        {
            for(int i = 0;i<tos;i++)
            {
                if(stk[i] == s.stk[i])
                    count++;
            }
            return (count == tos);
        }
        else
            return 0;
    }
    friend void ViewContent(const stack &s2);
};
void ViewContent(const stack &s2){
    if(s2.size)
    {
        cout << "View Content:" << endl;
        for(int i=0;i<s2.tos;i++)
            cout << s2.stk[i] << "\t";
        cout << endl;
    }
    else
        cout <<"Empty Stack"<<endl;
}

int main()
{
    stack s1(5) , s2(5) , s3;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.push(4);
    s2.push(5);
    s3 = s1+s2;
    ViewContent(s3);
}
