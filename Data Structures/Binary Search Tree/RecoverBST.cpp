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

void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void calculatePointers(node* root, node** first, node** mid, node** last, node** prev) // we can do call by reference as well
{
    if(root == NULL)
    return;

    calculatePointers(root->left, first, mid, last, prev);
    
    if(*prev && root->data < (*prev)->data)
    {
        if(!*first) // first is null in first violation
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
    *prev = root;
    calculatePointers(root->right, first, mid, last, prev);
}

void restoreBST(node* root)
{
    node *first, *mid, *last, *prev;
    first = NULL, mid = NULL, last = NULL, prev = NULL;

    calculatePointers(root,&first,&mid,&last,&prev);

    if(first && last)
    swap(&(first->data), &(last->data));
    else if(first && mid)
    swap(&(first->data), &(mid->data));
}

void inorder(node* root)
{
    if(root == NULL)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    node* root = new node(6);
    root->left = new node(9);
    root->right= new node(3);
    root->left->left = new node(1);
    root->left->right = new node(4);
    root->right->right = new node(13);

    inorder(root);
    cout<<endl;
    restoreBST(root);
    inorder(root);
    cout<<endl;
    return 0;
}