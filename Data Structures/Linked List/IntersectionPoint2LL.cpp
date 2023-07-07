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

void makeIntersection(node* &head1, node* &head2, int pos) // linking the last element of head 2 list to the pos point of 1st list
{
    node* temp1 = head1;
    pos--;
    while(pos)
    {
        temp1 = temp1->next;
        pos--;
    }

    node* temp2 = head2;
    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    temp2->next = temp1;
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

int intersection(node* head1, node* head2) //O(max l)
{
    int len1 = lengthll(head1);
    int len2 = lengthll(head2);

    node* ptr1;
    node* ptr2;
    int diff;

    if(len1 > len2)
    {
        diff = len1-len2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        diff = len2-len1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while(diff)
    {   
        ptr1 = ptr1->next;

        if(ptr1 == NULL)
        return -1;

        diff--;
    }
    
    while(ptr1->next != NULL && ptr2->next != NULL)
    {
        if(ptr1->data == ptr2->data)
        return ptr1->data;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

void display(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

int main()
{
    node* head = NULL;
    node* head2 = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);

    insertAtTail(head2,9);
    insertAtTail(head2,10);
    makeIntersection(head,head2,5);

    cout<<intersection(head,head2)<<"\n";
    //display(head);
    return 0;
}