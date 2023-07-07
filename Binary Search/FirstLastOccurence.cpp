#include <iostream>
using namespace std;

int search(int arr[], int n, int key) // first occurence
{
    int low = 0, high = n-1;
    int res = -1;

    while(low <= high)
    {
        int mid = low + (high-low)/2;

        if(arr[mid] == key)
        {
            res = mid;
            high = mid-1; // for last occurence, do low = mid+1;
        }
        else if(arr[mid] > key)
        high = mid-1;
        else
        low = mid+1;
    }
    return res;
}

int main()
{
    int arr[] = {1,2,3,4,4,4,5,6};
    int n = 8;
    int key = 4;
    
    cout<<search(arr,n,key)<<"\n";
    return 0;
}