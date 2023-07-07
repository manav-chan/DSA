#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v; // declaration

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for(int i=0;i<v.size();i++) // 1 2 3
    cout<<v[i]<<"\n";

    vector<int>::iterator it; // iterator is a pointer
    for(it=v.begin();it!=v.end();it++) // 1 2 3
    cout<<*it<<"\n";

    for(auto element:v) // 1 2 3
    cout<<element<<"\n";

    v.pop_back(); // 1 2

    vector<int> v2 (3,50); // 50 50 50

    swap(v,v2);
    for(auto element:v)
    cout<<element<<"\n";

    for(auto element:v2)
    cout<<element<<"\n";

    sort(v.begin(),v.end());

    pair <int,char> p;
    p.first = 3;
    p.second = 'a';

    return 0;
}