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

bool identicalBST(node* root1, node* root2)
{
    if(root1 == NULL && root2 == NULL)
    return true;

    if(root1 == NULL || root2 == NULL)
    return false;

    if(!identicalBST(root1->left,root2->left))
    return false;
    if(!identicalBST(root1->right, root2->right))
    return false;

    if(root1->data == root2->data)
    return true;
}

int main()
{
    /*int preorder[] = {1,3,2,5};
    int n = sizeof(preorder)/sizeof(preorder[0]);

    node* root1 = constructBST(preorder, n, preorder[0], INT_MIN, INT_MAX);
    node* root2 = constructBST(preorder, n, preorder[0], INT_MIN, INT_MAX);*/

    node* root1 = new node(1);
    root1->right = new node(3);
    root1->right->left = new node(2);
    root1->right->right =new node(5);

    node* root2 = new node(1);
    root2->right = new node(3);
    root2->right->left = new node(2);
    root2->right->right =new node(5);
    root2->right->right->right = new node(6);
    
    cout<<identicalBST(root1,root2);
    cout<<"\n";
    return 0;
}