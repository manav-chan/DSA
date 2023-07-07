#include <iostream>
#include <math.h>
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

int height(node* root)
{
    if(root == NULL)
    return 0;

    return max(height(root->left), height(root->right)) + 1;
}

bool isBalanced(node* root) // O(n^2)
{
    if(root == NULL)
    return true;

    if(isBalanced(root->left) && isBalanced(root->right))
    {
        int lh = height(root->left);
        int rh = height(root->right);
        if(abs(lh - rh) <= 1)
        return true;
        else
        return false;
    }
    return false;
}

bool isBalancedopt(node* root, int* height) // O(n)
{
    if(root == NULL)
    {
        return true;
    }

    int lh = 0, rh = 0;
    if(isBalancedopt(root->left,&lh) == false)
    return false;
    if(isBalancedopt(root->right,&rh)== false)
    return false;

    *height = max(lh,rh) + 1;

    if(abs(lh-rh) <= 1)
    return true;
    else
    return false;
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

    cout<<isBalanced(root)<<"\n";

    int height = 0;
    cout<<isBalancedopt(root,&height)<<"\n";
    return 0;
}