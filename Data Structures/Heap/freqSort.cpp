#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void freqSort(int arr[], int n)
{
    unordered_map<int,int> freq;
    for(int i=0;i<n;i++)
    freq[arr[i]]++;

    priority_queue<pair<int,int>> maxh;
    for(auto i:freq) // i is a pair
    {
        maxh.push({i.second,i.first});
    }

    while(maxh.size() != 0)
    {
        int val = maxh.top().second;
        int ct  = maxh.top().first;
        for(int i=0;i<ct;i++)
        cout<<val<<" ";

        maxh.pop();
    }
    cout<<endl;
}

int main()
{
    int arr[] = {1,1,1,3,2,2,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    freqSort(arr,n);
    return 0;
}