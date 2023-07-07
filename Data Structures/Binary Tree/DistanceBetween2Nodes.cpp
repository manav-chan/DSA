#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int val)
    {
        data = val;
        left = NULL;
        right= NULL;
    }
};

node* LCA(node* root, int n1, int n2)
{
    if(root == NULL)
    return NULL;

    if(root->data == n1 || root->data == n2)
    return root;

    node* left = LCA(root->left,n1,n2); // like a find element
    node* right= LCA(root->right,n1,n2);

    if(left && right)
    return root;

    if(left != NULL)
    return left;
    else
    return right;
}

int findDist(node* root, int key, int dist)
{
    if(root == NULL)
    return -1;

    if(root->data == key)
    return dist;

    int left = findDist(root->left, key, dist+1);
    if(left != -1)
    return left;
    else
    return findDist(root->right, key, dist+1);
}

int distBtwNodes(node* root, int n1, int n2)
{
    node* lca = LCA(root,n1,n2);
    
    int d1 = findDist(root,n1,0);
    int d2 = findDist(root,n2,0);

    return d1+d2;
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right= new node(3);

    root->left->left = new node(4);
    root->right->right = new node(5);

    int n1 = 4, n2 = 5;
    cout<<distBtwNodes(root,n1,n2)<<"\n";
    return 0;
}