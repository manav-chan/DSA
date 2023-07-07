#include <iostream>
#include <queue>
using namespace std;

int kthSmallest(int arr[], int n, int k)
{
    priority_queue<int> maxh;
    for(int i=0;i<n;i++)
    {
        maxh.push(arr[i]);

        if(maxh.size() > k)
        maxh.pop();
    }
    return maxh.top();
}

int sumElems(int arr[], int n, int k1, int k2)
{
    int a = kthSmallest(arr,n,k1);
    int b = kthSmallest(arr,n,k2);

    int sum = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] > a && arr[i] < b)
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int arr[] = {1,3,12,5,15,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k1 = 3, k2 = 6;
    cout<<sumElems(arr,n,k1,k2);
    return 0;
}