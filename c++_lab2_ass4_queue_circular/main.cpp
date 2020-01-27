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
        cout << "\nQueue contain " << items_No << " items : \n";
        if (!isEmpty())
        {
            for (int i=0 ; i<items_No ; i++)
            {
                if (head+i < qsize)
                    cout << i+1 << ") "<< que[head+i] << endl ;
                else
                    cout << i+1 << ") "<< que[i-(head+tail-1)] << endl ;
            }
        }
        else
            cout << "Queue is Empty." << endl ;

    }

    void viewArrayContent ()
    {
        cout << "\nArray contain " << items_No << " items and " << qsize-items_No << " garbage values: \n";
        if (!isEmpty())
        {
            for (int i=0 ; i<qsize ; i++)
                cout << i+1 << ") "<< que[i] << endl ;
        }
        else
            cout << "Array is Empty." << endl ;
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
            if(tail == qsize)
                tail=0;
            que[tail++] = val ;
            items_No++;
        }
        else
            cout << "Queue is full" << endl ;
    }

    void dequeue ()
    {
        if (!isEmpty())
        {
            if (head==qsize)
                head=0;
            cout << que[head++] << " is out of the queue." << endl ;
            items_No--;
        }
        else
            cout << "Queue is Empty." << endl ;
    }

    void peak ()
    {
        if (!isEmpty())
        {
            cout << que[tail-1] << " is the last item in the queue." << endl ;
        }
        else
            cout << "Queue is Empty." << endl ;
    }

};
int main()
{
    Queue q;
    q.dequeue();
    q.viewArrayContent();
    q.viewContent();
    q.enqueue(1);
    q.enqueue(8);
    q.enqueue(5);
    q.enqueue(4);
    q.dequeue();
    q.viewArrayContent();
    q.viewContent();
    q.enqueue(10);
    q.enqueue(11);
    q.dequeue();
    q.enqueue(12);
    q.peak();
    q.viewArrayContent();
    q.viewContent();
    return 0;
}
