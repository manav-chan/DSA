#include <iostream>
using namespace std;

void Merge(int arr[], int l, int mid, int r)
{
    int n1,n2;
    n1 = mid-l+1, n2 = r-mid;
    int a[n1], b[n2];

    for(int i=0;i<n1;i++)
    a[i] = arr[l+i];

    for(int i=0;i<n2;i++)
    b[i] = arr[mid+1+i];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2)
    {
        if(a[i] < b[j])
        {
            arr[k] = a[i];
            i++, k++;
        }
        else{
            arr[k] = b[j];
            j++, k++;
        }
    }

    while(i < n1)
    arr[k++] = a[i++];

    while(j < n2)
    arr[k++] = b[j++];
}

void MergeSort(int a[], int l, int r)
{
    if(l < r)
    {
        int mid = (l+r)/2;
        MergeSort(a,l,mid);
        MergeSort(a,mid+1,r);

        Merge(a,l,mid,r);
    }
}

int main()
{
    int n;
    cout<<"Enter array size\n";
    cin>>n;
    int arr[n];
    
    cout<<"Enter array elements\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];

    MergeSort(arr,0,n-1);
    cout<<"Sorted Array\n";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

    return 0;
}