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

node* buildBBST(int arr[], int start, int end) // similar to binary search
{
    if(start > end)
    return NULL;

    int mid = (start + end) / 2;

    node* root = new node(arr[mid]);
    root->left = buildBBST(arr, start, mid-1);
    root->right= buildBBST(arr, mid+1, end);

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
    int arr[] = {1,2,3,4,5};
    node *root = buildBBST(arr,0,4); 
    if(checkBST(root,NULL,NULL))
    printf("Valid BST\n");
    else
    printf("Invalid BST\n");    
    return 0;
}