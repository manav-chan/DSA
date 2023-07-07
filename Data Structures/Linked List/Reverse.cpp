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

node* reverse(node* &head) // iterative
{
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;
}

node* reverseRecursive(node* &head) // recursive
{
    if(head == NULL || head->next == NULL)
    return head;

    node* newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

node* reverseK(node* &head, int k)
{
    node* check = head; // if nodes are less than k then don't reverse
    for(int i=0;i<k;i++)
    {
        if(check == NULL)
        return head;

        check = check->next;
    }

    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    int count = 0;
    while(currptr != NULL && count < k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if(nextptr != NULL)
    head->next = reverseK(nextptr,k);

    return prevptr;
}

int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    // insertAtTail(head,6);

    display(head);

    head = reverse(head);
    display(head);
    head = reverseRecursive(head);
    display(head);
    head = reverseK(head,3);
    display(head);
    
    return 0;
}