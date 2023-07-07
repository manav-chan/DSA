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

int maxPathSumUtil(node* root, int &ans)
{
    if(root == NULL)
    return 0;

    int val = root->data;
    int lmax = maxPathSumUtil(root->left,ans);
    int rmax = maxPathSumUtil(root->right,ans);
    int nodemax = max(max(val, lmax + val), max(rmax + val, lmax + rmax + val));

    ans = max(ans, nodemax);

    return max(val, max(lmax + val, rmax + val));
}

int maxPathSum(node* root)
{
    int ans = INT_MIN;
    maxPathSumUtil(root,ans);
    return ans;
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right= new node(3);

    root->left->left = new node(4);
    root->right->right = new node(5);

    cout<<maxPathSum(root)<<"\n";
    return 0;
}