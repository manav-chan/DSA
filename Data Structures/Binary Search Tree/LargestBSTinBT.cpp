#include <iostream>
#include <climits>
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

class Info
{
    public:
    int size;
    int min;
    int max;
    int ans;
    bool isBST;
};

Info LargestBST(node* root)
{
    if(root == NULL)
    {
        return {0, INT_MAX, INT_MIN, 0, true};
    }

    Info leftinfo = LargestBST(root->left);
    Info rightinfo = LargestBST(root->right);
    Info curr;

    curr.size = leftinfo.size + rightinfo.size + 1;

    if(leftinfo.isBST && rightinfo.isBST && root->data > leftinfo.max && root->data < rightinfo.min)
    {
        curr.min = min(root->data, leftinfo.min);
        curr.max = max(root->data, rightinfo.max);

        curr.ans = curr.size;
        curr.isBST = true;

        return curr;
    }

    // not BST
    curr.ans = max(leftinfo.ans, rightinfo.ans);
    curr.isBST = false;
    
    return curr;
}

int main()
{
    node* root = new node(15);
    root->left = new node(20);
    root->right= new node(30);
    root->left->left = new node(5);

    cout<<"Largest BST size is : "<<LargestBST(root).ans<<"\n";
    return 0;
}