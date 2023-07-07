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

node* mergeRecursive(node* head1, node* head2)
{
    if(head1 == NULL)
    return head2;

    if(head2 == NULL)
    return head1;

    node* result;
    if(head1->data < head2->data)
    {
        result = head1;
        result->next = mergeRecursive(head1->next,head2);
    }
    else
    {
        result = head2;
        result->next = mergeRecursive(head1,head2->next);
    }

    return result;
}

node* merge(node* &head1, node* &head2) //O(m+n)
{
    node* p1 = head1;
    node* p2 = head2;
    node* dummyNode = new node(-1);
    node* p3 = dummyNode;

    while(p1!=NULL && p2!=NULL)
    {
        if(p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    if(p1!=NULL) // smart
    {
        p3->next = p1;
    }
    if(p2!=NULL)
    {
        p3->next = p2;
    }

    return dummyNode->next;
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
    node* head2 = NULL;
    insertAtTail(head,1);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,7);
    display(head);

    insertAtTail(head2,2);
    insertAtTail(head2,3);
    insertAtTail(head2,6);
    display(head2);

    //node* newhead = merge(head,head2);
    node* newhead2= merge(head,head2);

    //display(newhead);
    display(newhead2);

    return 0;
}