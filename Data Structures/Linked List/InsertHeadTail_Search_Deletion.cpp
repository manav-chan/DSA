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

bool search(node* head, int key)
{
    node* temp = head;

    while(temp != NULL)
    {
        if(temp->data == key)
        return true;
        else
        temp = temp->next;
    }
    return false;
}

void deleteAtHead(node* &head)
{
    node* todelete = head;

    head = head->next;
    delete todelete;

}

void deletion(node* &head, int val)
{
    if(head == NULL)
    return;

    if(head->next == NULL || head->data == val)
    {
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    while(temp->next->data != val)
    {
        temp = temp->next;

        if(temp->next == NULL)
        {
            cout<<"Element Not Found\n";
            return;
        }
    }

    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete; // prevents memory leak
}

node* reverse(node* &head)
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

int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);

    display(head);

    insertAtHead(head,5);
    display(head);
    
    if(search(head,2))
    cout<<"Found\n";
    else
    cout<<"Not Found\n";

    deletion(head,3);
    display(head);
    deletion(head,8);
    display(head);
    deletion(head,5);
    display(head);

    head = reverse(head);
    display(head);

    return 0;
}