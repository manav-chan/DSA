#include <iostream>
using namespace std;

int SelectionSort(int arr[], int n)
{
    for(int i=0;i<=n-2;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(arr[j]<arr[i])
            {
                int temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

int BubbleSort(int arr[], int n)
{
    for(int i=0;i<=n-2;++i)
    {
        for(int j=0;j<=n-i-2;++j)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

int InsertionSort(int arr[], int n)
{
    for(int i=1;i<n;++i)
    {
        int k=arr[i];
        int j=i-1;
        while(arr[j]>k && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=k;
    }
    for(int i=0;i<n;++i)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

int main()
{
    int n,a;
    cout<<"Enter array size\n";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements\n";
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    cout<<"Select sorting technique: 1.Selection Sort 2.Bubble Sort 3.Insertion Sort\n";
    cin>>a;
    switch (a)
    {
        case 1:
        SelectionSort(arr,n);
        break;
        case 2:
        BubbleSort(arr,n);
        break;
        case 3:
        InsertionSort(arr,n);
        break;
        default:
        cout<<"Enter correctly\n";
        break;
    }
    return 0;
}