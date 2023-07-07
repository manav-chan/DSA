#include <iostream>
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

node* insertBST(node* root, int val)
{
    if(root == NULL)
    return new node(val);

    if(val < root->data)
    root->left = insertBST(root->left,val);
    else //(val > root->data)
    root->right= insertBST(root->right,val);

    return root;
}

node* searchBST(node* root, int key)
{
    if(root == NULL)
    return NULL;

    if(root->data == key)
    return root;

    if(root->data > key)
    return searchBST(root->right, key);

    //if(root->data < key)
    return searchBST(root->left, key);
}

node* inorderSucc(node* root)
{
    node* temp = root;
    while(temp && temp->left)
    {
        temp = temp->left;
    }
    return temp;
}

node* deleteBST(node* root, int key)
{
    if(root->data > key)
    root->left = deleteBST(root->left,key);
    else if(root->data < key)
    root->right = deleteBST(root->right,key);

    else // if (root->data == key)
    {
        if(root->left == NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }
        // case 3
        node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
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
    int arr[] = {5,1,3,4,2,7};
    node* root = NULL;

    root = insertBST(root,arr[0]);
    for(int i=1; i<sizeof(arr)/sizeof(arr[0]); i++)
    insertBST(root,arr[i]);

    inorder(root);
    cout<<"\n";

    root = deleteBST(root,3);
    inorder(root);
    cout<<"\n";

    return 0;
}