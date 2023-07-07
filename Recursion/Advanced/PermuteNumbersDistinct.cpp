#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> ans;

void Permute(vector<int> &a, int idx) // for distinct elements only
{
    if(idx == a.size()-1)
    {
        ans.push_back(a);
        return;
    }

    for(int i=idx;i<a.size();i++)
    {
        swap(a[i],a[idx]);
        Permute(a,idx+1);
        swap(a[i],a[idx]);
    }
    return;
}

void PermuteSTL(vector<int> &a)
{
    sort(a.begin(),a.end());
    do
    {
        ans.push_back(a);
    } while(next_permutation(a.begin(),a.end()));
}

int main()
{
    int n;
    cout<<"Enter size of array\n";
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];

    Permute(a,0);
    //PermuteSTL(a);

    for(auto v:ans)
    {
        for(auto i:v)
        cout<<i<<" ";

        cout<<"\n";
    }
    return 0;
}