#include <iostream>
#define n 100
using namespace std;

class queue
{
    int* arr;
    int front,back;

    public:
    queue()
    {
        arr = new int[n];
        front = back = -1;
    }

    void push(int val)
    {
        if(back == n-1)
        {
            cout<<"Queue Overflow\n";
            return;
        }
        
        arr[++back] = val;

        if(front == -1)
        front++;
    }

    void pop()
    {
        if(front == -1 || front > back)
        {
            cout<<"No element to delete\n";
            return;
        }
        front++;
    }

    int peek()
    {
        if(front == -1 || front > back)
        {
            cout<<"No element\n";
            return -1;
        }
        return arr[front];
    }

    bool empty()
    {
        if(front == -1 || front > back)
        return true;
        
        return false;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.peek()<<"\n";
    q.pop();

    cout<<q.peek()<<"\n";
    q.pop();

    cout<<q.peek()<<"\n";
    q.pop();

    cout<<q.peek()<<"\n";
    q.pop();

    cout<<q.empty()<<"\n";

    return 0;
}