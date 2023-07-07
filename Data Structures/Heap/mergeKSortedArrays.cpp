#include <bits/stdc++.h> 

class node
{
    public:
    int data;
    int row;
    int col;
    
    node(int val, int i, int j)
    {
        data = val;
        row = i;
        col = j;
    }
};

class compare
{
    public:
    bool operator()(node* a, node* b)
    {
        return a->data > b->data;
    }
}

vector<int> mergekSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*, vector<node*>, compare> minh;
    vector<int> ans;
    for(int i=0; i<kArrays.size(); i++)
    {
        node* temp = new node(kArrays[i][0], i, 0);
        minh.push(temp);
    }
    
    while(minh.size() > 0)
    {
        node* temp = minh.top();
        ans.push_back(temp->data);
        minh.pop();
        
        int i = temp->row;
        int j = temp->col;
        delete(temp);
        
        if(j+1 < kArrays[i].size())
        {
            temp = new node(kArrays[i][j+1], i, j+1);
            minh.push(temp);
        }
    }
    return ans;
}
