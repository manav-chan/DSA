#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right= NULL;
    }
};

int search(int inorder[], int start, int end, int curr)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i] == curr)
        return i;
    }
    return -1;
}

Node* buildTree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if(start > end)
    return NULL;

    int curr = preorder[idx];
    idx++;
    Node* node = new Node(curr);

    if(start == end)
    return node;
    
    int pos = search(inorder,start,end,curr);
    node->left = buildTree(preorder,inorder,start,pos-1);
    node->right= buildTree(preorder,inorder,pos+1,end);

    return node;
}

void inorderprint(Node* head)
{
    if(head == NULL)
    return;
    
    inorderprint(head->left);
    cout<<head->data<<" ";
    inorderprint(head->right);
}

int main()
{
    int preorder[]= {1,2,4,5,3,6,7};
    int inorder[] = {4,2,5,1,6,3,7};
    Node* head = buildTree(preorder,inorder,0,6);
    inorderprint(head);
    return 0;
}