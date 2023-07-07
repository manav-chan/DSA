#include <iostream>
using namespace std;

int Partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l-1;

    for(int j=l;j<=r-1;j++)
    {
        if(arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[r],arr[i+1]);

    return i+1;
}

void QuickSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int pi = Partition(arr,l,r);

        QuickSort(arr,l,pi-1);
        QuickSort(arr,pi+1,r);
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

    QuickSort(arr,0,n-1);
    cout<<"Sorted Array\n";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

    return 0;
}