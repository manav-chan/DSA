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

void subtreeNodes(node* root, int k)
{
    if(root == NULL || k < 0)
    return;

    if(k == 0)
    {
        cout<<root->data<<" ";
        return;
    }

    subtreeNodes(root->left, k-1);
    subtreeNodes(root->right,k-1);
}

int printAllNodesK(node* root, node* target, int k)
{
    if(root == NULL)
    return -1;

    if(root == target)
    {
        subtreeNodes(root,k);
        return 0;
    }

    int leftdis = printAllNodesK(root->left, target, k);
    if(leftdis != -1)
    {
        if(leftdis + 1 == k)
        cout<<root->data<<" ";

        else
        subtreeNodes(root->right, k-leftdis-2);

        return leftdis + 1;
    }

    int rightdis = printAllNodesK(root->right, target, k);
    if(rightdis != -1)
    {
        if(rightdis + 1 == k)
        cout<<root->data<<" ";

        else
        subtreeNodes(root->left, k-rightdis-2);

        return rightdis + 1;
    }
    return -1;
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right= new node(3);
    /*        1
            2   3
          4       5
    */
    root->left->left = new node(4);
    root->right->right = new node(5);

    printAllNodesK(root,root->left,1);
    cout<<endl;
    
    return 0;
}