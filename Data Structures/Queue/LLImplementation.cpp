#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class queue
{
    node* front;
    node* back;

    public:
    queue()
    {
        front = NULL;
        back = NULL;
    }

    void push(int val)
    {
        node* n = new node(val);
        if(front == NULL)
        {
            front = n;
            back = n;
            return;
        }

        back->next = n;
        back = back->next;
    }

    void pop()
    {
        if(front == NULL)
        {
            cout<<"Queue underflow\n";
            return;
        }

        node* todelete = front;
        front = front->next;
        delete todelete;
    }

    int peek()
    {
        if(front == NULL)
        {
            cout<<"No element\n";
            return -1;
        }
        return front->data;
    }

    bool empty()
    {
        if(front == NULL)
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

    cout<<q.peek()<<"\n";
    q.pop();

    cout<<q.peek()<<"\n";
    q.pop();

    cout<<q.peek()<<"\n";
    q.pop();

    cout<<q.empty()<<"\n";

    return 0;
}