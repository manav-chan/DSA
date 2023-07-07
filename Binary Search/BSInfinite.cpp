#include <iostream>
using namespace std;

int BS(int arr[], int start, int end, int key) 
{
    while(start <= end)
    {
        int mid = start + (end-start)/2;

        if(arr[mid] == key)
        return mid;

        else if(arr[mid] < key)
        start = mid+1;

        else if(arr[mid] > key)
        end = mid-1;
    }
    return -1;
}

int BSInfinite(int arr[], int n, int key)
{
    int start = 0, end = 1;
    while(arr[end] < key)
    {
        start = end;
        end *= 2; // double end for logn complexity
    }
    int result = BS(arr,start,end,key);
    return result;
}

int main()
{
    int arr[] = {1,2,3,4,8,10,10,12,19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 8;

    cout<<"Element found at index: "<<BSInfinite(arr,n,key)<<"\n";
    return 0;
}