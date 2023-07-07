#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int m, t;
    cin>>m>>t;

    vector<pair<int,int> > ans;
    for(int i=0; i<m; i++)
    {
        vector<pair<int, int> > subtasks;
        vector<int> sc(t);
        for(auto &j: sc)
        cin>>j;

        vector<int> ns(t);
        for(auto &j :ns)
        cin>>j;

        for(int j=0; j<t; j++)
        {
            pair<int, int> p = make_pair(sc[j], ns[j]);
            subtasks.push_back(p);
        }

        sort(subtasks.begin(), subtasks.end());
        int n = 0;
        for(int j=0; j<t-1; j++)
        {
            if(subtasks[j].second > subtasks[j+1].second)
            n++;
        }
        pair<int, int> p = make_pair(n, i);
        ans.push_back(p);
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<m; i++)
    {
        cout<<ans[i].second+1<<endl;
    }
}