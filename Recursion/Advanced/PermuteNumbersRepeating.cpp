#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> ans;

void Permute(vector<int> a, int idx) // for repeating elements
{
    if(idx == a.size())
    {
        ans.push_back(a);
        return;
    }
    for(int i=idx;i<a.size();i++)
    {
        if(i != idx && a[i] == a[idx])
        continue;

        swap(a[i],a[idx]);
        Permute(a,idx+1);
    }
    return;
}

int main()
{
    int n;
    cout<<"Enter array size\n";
    cin>>n;

    vector<int> a(n);
    cout<<"Enter array elements\n";
    for(auto &i:a)
    cin>>i;

    sort(a.begin(),a.end());
    Permute(a,0);
    for(auto v:ans)
    {
        for(auto i:v)
        cout<<i<<" ";

        cout<<"\n";
    }
    return 0;
}