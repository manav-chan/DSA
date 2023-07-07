#include <iostream>
#include <queue>
using namespace std;

void kClosest(int arr[], int n, int k, int x)
{
    priority_queue<pair<int,int>> maxh;
    for(int i=0;i<n;i++)
    {
        maxh.push({abs(x-arr[i]), arr[i]});
        if(maxh.size() > k)
        maxh.pop();
    }

    while(maxh.size() != 0)
    {
        cout<<maxh.top().second<<" ";
        maxh.pop();
    }
}

int main()
{
    int arr[] = {5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3, x = 7;
    kClosest(arr,n,k,x);
    return 0;
}