#include <iostream>
using namespace std;

int search(int arr[], int n, int key) // first occurence
{
    int low = 0, high = n-1;

    while(low <= high)
    {
        int mid = low + (high-low)/2;

        if(arr[mid] == key)
        return mid;

        else if((mid-1 >= low) && arr[mid-1] == key)
        return mid-1;

        else if((mid+1 <= high) && arr[mid+1] == key)
        return mid+1;
        
        else if(key > arr[mid])
        low = mid + 2;
        
        else
        high = mid - 2;
    }
    return -1; 
}

int main()
{
    int arr[] = {5,10,30,20,40};
    int n = 5;
    int key = 20;
    
    cout<<search(arr,n,key)<<"\n";
    return 0;
}