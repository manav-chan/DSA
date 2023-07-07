#include <iostream>
using namespace std;

void WaveSort(int arr[], int n)
{
    for(int i=1; i<n; i+=2)
    {
        if(arr[i] > arr[i-1])
        swap(arr[i],arr[i-1]);

        if((i<=n-2) && (arr[i] > arr[i+1]))
        swap(arr[i],arr[i+1]);
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

    WaveSort(arr,n);
    cout<<"Sorted Array\n";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

    return 0;
}