#include <iostream>
using namespace std;

int mindiff(int arr[], int n, int key)
{
    int low = 0, high = n-1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid] == key)
        return mid;

        else if(arr[mid] > key)
        high = mid-1;

        else
        low = mid+1;
    }

    if(abs(arr[low] - key) < abs(arr[high] - key))
    return low;
    else
    return high;
}

int main()
{
    int arr[] = {1,3,8,10,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 12;

    cout<<mindiff(arr,n,key)<<"\n";
    return 0;
}