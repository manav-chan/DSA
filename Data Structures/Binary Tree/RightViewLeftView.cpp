#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void rightView(node* root) // O(n)
{
    if(root == NULL)
    return;

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* val = q.front();
        q.pop();

        if(q.front() == NULL) // to get the rightmost element
        cout<<val->data<<" ";

        if(val != NULL)
        {
            if(val->left)
            q.push(val->left);
            if(val->right)
            q.push(val->right);
        }
        else if(!q.empty())
        q.push(NULL);
    }
}

void leftView(node* root) // O(n)
{
    if(root == NULL)
    return;

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* val = q.front();
        q.pop();

        if(q.front() == NULL) // to get the leftmost element
        cout<<val->data<<" ";

        if(val != NULL)
        {
            if(val->right)
            q.push(val->right);
            if(val->left)
            q.push(val->left);
        }
        else if(!q.empty())
        q.push(NULL);
    }
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right= new node(3);

    root->left->left = new node(4);
    root->left->right= new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    rightView(root);
    cout<<endl;
    leftView(root);
    cout<<endl;

    return 0;
}