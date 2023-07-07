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

bool checkBST(node* root, node* min, node* max)
{
    if(root == NULL)
    return true;

    if(min != NULL && root->data <= min->data)
    return false;

    if(max != NULL && root->data >= max->data)
    return false;

    bool leftvalid = checkBST(root->left, min, root);
    bool rightvalid= checkBST(root->right,root, max);
    return leftvalid && rightvalid;
}

int main()
{
    int preorder[] = {7,5,4,6,8,9};
    int n = sizeof(preorder)/sizeof(preorder[0]);

    node* root = constructBST(preorder, n, preorder[0], INT_MIN, INT_MAX);

    node* root2 = new node(1);
    root2->left = new node(2);
    root2->right= new node(3);
    if(checkBST(root2,NULL,NULL))
    printf("Valid BST\n");
    else
    printf("Invalid BST\n");    
    return 0;
}