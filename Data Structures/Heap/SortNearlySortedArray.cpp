#include <iostream>
#include <queue>
using namespace std;

void sortNearlySorted(int arr[], int n, int k)
{
    int temp[n], t=0;
    priority_queue<int,vector<int>,greater<int>> minh;

    for(int i=0;i<n;i++)
    {
        minh.push(arr[i]);
        if(minh.size() > k)
        {
            temp[t++] = minh.top();
            minh.pop();
        }
    }

    while(minh.size() != 0)
    {
        temp[t++] = minh.top();
        minh.pop();
    }

    for(int i=0;i<n;i++)
    arr[i] = temp[i];
}

int main()
{
    int arr[] = {6,5,3,2,8,10,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    sortNearlySorted(arr,n,k);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

    return 0;
}