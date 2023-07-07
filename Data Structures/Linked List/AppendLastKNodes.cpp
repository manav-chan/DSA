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

void insertAtTail(node* &head, int val)
{
    node* n = new node(val);

    if(head == NULL) // head will get an initial value from this
    {
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead(node* &head, int val)
{
    node* n = new node(val);
    // we don't need if condition here as it will be resolved automatically
    n->next = head;
    head = n;
}

int lengthll(node* head)
{
    node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void appendk(node* &head, int k)
{
    node* newhead;
    node* newtail;
    node* tail;

    int l = lengthll(head);
    int count = 1;
    tail = head;
    k = k%l;
    while(tail->next != NULL)
    {
        if(count == (l-k))
        newtail = tail;

        if(count == (l-k+1))
        newhead = tail;

        tail = tail->next;
        count++;
    }

    tail->next = head;
    newtail->next = NULL;
    head = newhead; // we can return new head as well
}

void display(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);

    display(head);

    appendk(head,2);
    display(head);

    return 0;
}