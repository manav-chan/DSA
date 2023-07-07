#include <iostream>
#include <climits>
using namespace std;

bool isPossible(int arr[], int n, int m, int min)
{
    int painters = 1, sum = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] > min)
        return false;

        if(sum + arr[i] > min)
        {
            painters ++;
            sum = arr[i];

            if(painters > m)
            return false;
        }
        else
        sum += arr[i];
    }
    return true;
}

int paintersPartition(int arr[], int n, int m)
{
    if(m > n)
    return -1;

    int sum = 0;
    for(int i=0;i<n;i++)
    sum += arr[i];

    int left = 0, right = sum;
    int result = INT_MAX;

    while(left <= right)
    {
        int mid = (left+right)/2;

        if(isPossible(arr,n,m,mid))
        {
            right = mid-1;
            result = min(result, mid);
        }
        else
        left = mid+1;
    }
    return result;
}

int main()
{
    int arr[] = {10,20,30,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = 2;

    cout<<paintersPartition(arr,n,m)<<"\n";
    return 0;
}