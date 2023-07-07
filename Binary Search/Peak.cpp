#include <iostream>
using namespace std;

int peak(int arr[], int n) // same concept for finding max element in bitonic array (monotonically inc then decreasing)
{
    int low = 0, high = n-1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(mid > 0 && mid < n-1)
        {
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
            return mid;

            else if(arr[mid+1] > arr[mid]) // rising slope on the right
            low = mid+1;

            else // rising slope on the left
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

int main()
{
    int arr[] = {5,10,20,15};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<peak(arr,n)<<"\n";
    return 0;
}