#include <iostream>
using namespace std;

int peak(int arr[], int n)
{
    int low = 0, high = n-1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(mid > 0 && mid < n-1)
        {
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
            return mid;

            else if(arr[mid+1] > arr[mid])
            low = mid+1;

            else
            high = mid-1;
        }
        
        else if(mid == 0)
        {
            if(arr[0] > arr[1])
            return 0;
            else
            return 1;
        }
        else if(mid == n-1)
        {
            if(arr[n-1] > arr[n-2])
            return n-1;
            else
            return n-2;
        }
    }
}

int BS(int arr[], int start, int end, int key)
{
    while(start <= end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid] == key)
        return mid;

        else if(arr[mid] > key)
        end = mid-1;

        else
        start = mid+1;
    }
    return -1;
}

int searchBitonic(int arr[], int n, int key)
{
    int idx  = peak(arr,n);
    int res1 = BS(arr,0,idx,key);
    int res2 = BS(arr,idx+1,n-1,key);

    return max(res1,res2);
}

int main()
{
    int arr[] = {1,3,8,12,4,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 4;

    cout<<searchBitonic(arr,n,key);
    return 0;
}