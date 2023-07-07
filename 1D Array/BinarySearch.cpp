#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int k)
{
    int low=0;
    int high=n;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(k==arr[mid])
        return mid+1;
        else if(arr[mid]>k)
        high=mid-1;
        else
        low=mid+1;
    }
    return -1;
}

int main()
{
    int n,k;
    cout<<"Enter array size\n";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter key\n";
    cin>>k;
    cout<<"Position is: "<<BinarySearch(arr,n,k)<<endl;
    return 0;
}