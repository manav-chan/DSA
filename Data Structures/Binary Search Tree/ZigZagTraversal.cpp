#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <algorithm>
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

void ZigZag(node* root) //O(n)
{
    if(root == NULL)
    return;

    bool LtoR = true;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    vector<int> ans;

    while(!q.empty())
    {
        node* val = q.front();
        q.pop();
        if(val != NULL)
        {
            ans.push_back(val->data);
            if(val->left)
            q.push(val->left);
            if(val->right)
            q.push(val->right);
            
        }
        else
        {
            if(LtoR)
                {
                for(auto elem:ans)
                cout<<elem<<" ";
                ans = {};
                }
                else
                {
                reverse(ans.begin(),ans.end());
                for(auto elem:ans)
                cout<<elem<<" ";
                ans = {};
            }    
            if(!q.empty())
            {
                q.push(NULL);
                LtoR = !LtoR;
            }
        }
    }
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right=  new node(3);
    root->left->right = new node(4);
    root->left->right->left= new node(6);
    root->left->right->right= new node(7);
    root->right->right= new node(5);
    ZigZag(root);
    cout<<endl;
    
    return 0;
}