#include <iostream>
using namespace std;

int timesArrayRotated(int arr[], int n) // first occurence
{
    int low = 0, high = n-1;

    while(low <= high)
    {
        if(arr[low] <= arr[high]) // if array is sorted, min is low
        return low;

        int mid = low + (high-low)/2;
        int next = (mid+1) % n, prev = (mid+n-1) % n;

        if(arr[mid] <= arr[prev] && arr[mid] <= arr[next]) // base condition
        return mid;

        else if(arr[low] <= arr[mid]) // right part is unsorted
        low = mid + 1;
        
        else if(arr[mid] <= arr[high]) // left part is unsorted
        high = mid - 1;
    }
}

int main()
{
    int arr[] = {5,6,8,11,12,15,18,2};
    int n = 8;
    
    cout<<timesArrayRotated(arr,n)<<"\n";
    return 0;
}