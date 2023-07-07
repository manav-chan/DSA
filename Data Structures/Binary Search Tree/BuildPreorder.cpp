#include <iostream>
#include <climits>
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

node* constructBST(int preorder[], int n, int key, int min, int max) // O(n)
{
    static int idx = 0;
    if(idx >= n) // base case
    return NULL;

    node* root = NULL;
    if(key > min && key < max)
    {
        root = new node(key);
        idx++;

        if(idx < n)
        root->left = constructBST(preorder,n, preorder[idx], min, key);
        if(idx < n)
        root->right= constructBST(preorder,n, preorder[idx], key, max);
    }
    return root;
}

void printpreorder(node* root)
{
    if(root == NULL)
    return;

    cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right);
}

int main()
{
    int preorder[] = {7,5,4,6,8,9};
    int n = sizeof(preorder)/sizeof(preorder[0]);

    node* root = constructBST(preorder, n, preorder[0], INT_MIN, INT_MAX);
    printpreorder(root);
    
    return 0;
}