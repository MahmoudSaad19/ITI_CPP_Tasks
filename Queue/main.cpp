#include <iostream>

#define deafaultSize 5

using namespace std;

class Queue
{
    int head, tail , *que , qsize , items_No ;

public:

    Queue (int s= deafaultSize)
    {
        head =0;
        tail =0 ;
        items_No = 0 ;
        qsize = s;
        que = new int [qsize] ;
    }

    ~Queue ()
    {
        delete []que ;
    }

    void viewContent ()
    {
        if (!isEmpty())
        {
            for (int i=0 ; i<items_No ; i++)
                cout << i+1 << ") "<< que[i] << endl ;
        }
        else
            cout << "Queue is Empty." << endl ;

    }

    int isFull ()
    {
        return items_No == qsize ;
    }

    int isEmpty ()
    {
        return !items_No ;
    }

    void enqueue (int val)
    {
        if (!isFull())
        {
            cout << val << " is entered the queue." << endl ;
            que[items_No++] = val ;
            tail++;
        }
        else
            cout << "Queue is full" << endl ;
    }

    void dequeue ()
    {
        if (!isEmpty())
        {
            cout << que[0] << " is out of the queue." << endl ;
            tail--;
            for(int i=0 ; i<tail ; i++)
                que[i]=que[i+1];
            items_No--;
        }
        else
            cout << "Queue is Empty." << endl ;
    }

};
int main()
{
    Queue q;
    q.dequeue();
    q.viewContent();
    q.enqueue(1);
    q.enqueue(8);
    q.enqueue(5);
    q.enqueue(4);
    q.dequeue();
    q.viewContent();
    q.enqueue(10);
    q.enqueue(11);
    q.dequeue();
    q.enqueue(12);
    q.viewContent();
    return 0;
}
