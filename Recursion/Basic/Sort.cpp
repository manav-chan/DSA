#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int> &v, int val)
{
    if(v.size() == 0 || v[v.size()-1] <= val)
    {
        v.push_back(val);
        return;
    }

    int temp = v[v.size()-1];
    v.pop_back();
    insert(v,val);
    v.push_back(temp);
}

void sort(vector<int> &v)
{
    if(v.size() == 1)
    return;

    int temp = v[v.size()-1];
    v.pop_back();
    sort(v);
    insert(v,temp);
}

int main()
{
    vector<int> v = {2,3,7,6,4,5,9};
    sort(v);

    for(auto i:v)
    cout<<i<<" ";

    return 0;
}