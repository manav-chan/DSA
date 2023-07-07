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

int sumKthLevel(node* root, int k)
{
    if(root == NULL)
    return -1;

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    int count = 0;
    while(!q.empty() && count != k)
    {
        node* curr = q.front();
        q.pop();
        if(curr != NULL)
        {
            if(curr->left) // OR we can add the statement if(count == k) sum+= curr->data; then we can return sum for simple code. 
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);
        }
        else if(!q.empty())
        {
            q.push(NULL);
            count++;
        }
    }
    if(q.empty()) // level does not exist
    return -1;

    int sum = 0;
    while(q.front() != NULL) //queue contains kth level element
    {
        sum+= q.front()->data;
        q.pop();
    }
    return sum;
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

    int k = 2;
    cout<<sumKthLevel(root,k)<<"\n";
    return 0;
}
