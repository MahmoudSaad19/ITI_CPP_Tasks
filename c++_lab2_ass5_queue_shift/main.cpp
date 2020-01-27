#include <iostream>

#define deafaultSize 5
#define headOfQueue 0

using namespace std;
/*
this is queue class with shift operation
*/
class Queue
{
    int tail , *que , qsize , items_No ;

public:

    Queue (int s= deafaultSize)
    {
        tail =headOfQueue ;
        items_No = headOfQueue ;
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
            cout << "\nQueue content : " << endl ;
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
            cout << que[headOfQueue] << " is out of the queue." << endl ;
            tail--;
            for(int i=0 ; i<tail ; i++)
                que[i]=que[i+1];
            items_No--;
        }
        else
            cout << "Queue is Empty." << endl ;
    }

    void peak ()
    {
        if (!isEmpty())
        {
            cout << que[headOfQueue] << " is the last element of the queue." << endl ;
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
    q.peak();
    return 0;
}
