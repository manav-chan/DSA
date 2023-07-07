#include <iostream>
#include <set>
#include <vector>
#include <deque>
using namespace std;

void brute(vector<int> a, int n, int k) //O(nlogn)
{
    vector<int> ans;
    multiset<int, greater<int>> s;
    for(int i=0;i<k;i++)
    s.insert(a[i]);

    ans.push_back(*s.begin());
    for(int i=k;i<n;i++)
    {
        s.erase(s.lower_bound(a[i-k])); // if we use erase(a[i-k]) all values of that value will be erased, we want to erase only one value
        s.insert(a[i]);
        ans.push_back(*s.begin());
    }

    for(auto i:ans)
    cout<<i<<" ";
    cout<<"\n";
}

void slidingWindow(vector<int> a, int n, int k) // O(n)
{
    deque<int> q;
    vector<int> ans;
    for(int i=0;i<k;i++)
    {
        while(!q.empty() && a[i] > a[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(a[q.front()]);

    for(int i=k;i<n;i++)
    {
        if(q.front() == i-k)
        q.pop_front();

        while(!q.empty() && a[i] > a[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(a[q.front()]);
    }

    for(auto i:ans)
    cout<<i<<" ";
    cout<<endl;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &i:a)
    cin>>i;

    brute(a,n,k);
    slidingWindow(a,n,k);
    return 0;
}