#include <iostream>
#include <algorithm>
using namespace std;

bool isFeasible(int arr[], int n, int k, int mindist)
{
    int elements = 1, pos = arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i] - pos >= mindist)
        {
            pos = arr[i];
            elements ++;

            if(elements == k)
            return true;
        }
    }
    return false;
}

int largestMinDist(int arr[], int n, int k)
{
    sort(arr, arr+n);

    int result = -1;
    int left = 1, right = arr[n-1]-arr[0];

    while(left <= right)
    {
        int mid = left + (right-left)/2; // to prevent integer overflow otherwise use (left+right)/2

        if(isFeasible(arr,n,k,mid))
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else
        right = mid-1;
    }
    return result;
}

int main()
{
    int arr[] = {1,2,8,4,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    cout<<largestMinDist(arr,n,k)<<"\n";
    return 0;
}