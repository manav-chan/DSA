#include <iostream>
#include <vector>
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

vector<node*> constructTrees(int start, int end)
{
    vector<node*> trees;
    if(start > end)
    {
        trees.push_back(NULL);
        return trees;
    }

    for(int i=start; i<=end; i++)
    {
        vector<node*> leftsubtree = constructTrees(start, i-1);
        vector<node*> rightsubtree= constructTrees(i+1, end);

        for(int j=0; j<leftsubtree.size(); j++)
        {
            node* left = leftsubtree[j];
            for(int k=0; k<rightsubtree.size(); k++)
            {
                node* right = rightsubtree[k];

                node* Node = new node(i);
                Node->left = left;
                Node->right = right;
                trees.push_back(Node);
            }
        }
    }
    return trees;
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
    vector<node*> alltrees = constructTrees(1,3);
    for(int i=0;i<alltrees.size();i++)
    {
        cout<<i+1<<" : ";
        printpreorder(alltrees[i]);
        cout<<"\n";
    }
    return 0;
}