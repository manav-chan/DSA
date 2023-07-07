#include <queue>
#include <climits>
class node
{
    public:
    int data;
    int row;
    int col;
    
    node(int d, int i, int j)
    {
        data = d;
        row = i;
        col = j;
    }
};

class compare
{
    public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    priority_queue<node*,vector<node*>,compare> minh;
    int maxi = INT_MIN;
    
    for(int i=0; i<a.size(); i++)
    {
        node *temp = new node(a[i][0], i, 0);
        maxi = max(maxi, a[i][0]);
        minh.push(temp);
    }
    
    int range = INT_MAX;
    while(minh.size() > 0)
    {
        node* min = minh.top();
        minh.pop();
        
        int i = min->row;
        int j = min->col;
        int mini = min->data;
        
        if(maxi - mini < range)
            range = maxi - mini;
        if(j + 1 < a[i].size())
        {
            node *temp = new node(a[i][j+1], i, j+1);
            minh.push(temp);
            maxi = max(maxi, a[i][j+1]);
        }
        else
            break;
    }
    return range+1;
}