#include <iostream>
using namespace std;

void DNFSort(int arr[], int n) // works for 0,1,2 elements only
{
    int low,mid,high;
    low = 0, mid = 0, high = n-1;

    while(mid < high) // break condition mid == high
    {
        if(arr[mid] == 0)
        {
            swap(arr[low],arr[mid]);
            mid++,low++;
        }
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else // arr[mid] == 2
        {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main()
{
    int n;
    cout<<"Enter size of array\n";
    cin>>n;
    int arr[n];

    cout<<"Enter elements\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];

    DNFSort(arr,n);
    cout<<"Sorted Array\n";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

    return 0;
}