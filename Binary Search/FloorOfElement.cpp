#include <iostream>
using namespace std;

int floor(int arr[], int n, int key) // ceil also similar just do opposite
{
    int start = 0, end = n-1;
    int res = -1;
    while(start <= end)
    {
        int mid = start + (end-start)/2;

        if(arr[mid] == key)
        return arr[mid];

        else if(arr[mid] < key)
        {
            res = arr[mid];
            start = mid+1;
            if(start <=end && arr[start] > key)
            break;
        }

        else if(arr[mid] > key)
        end = mid-1;
    }
    return res;
}

int main()
{
    int arr[] = {1,2,3,4,8,10,10,12,19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 5;

    cout<<floor(arr,n,key)<<"\n";
    return 0;
}