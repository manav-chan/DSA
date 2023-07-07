#include <iostream>
using namespace std;

long long Merge(int arr[], int l, int mid, int r)
{
    long long inv = 0;
    int n1 = mid-l+1, n2 = r-mid;
    int a[n1], b[n2];

    for(int i=0;i<n1;i++)
    a[i] = arr[l+i];

    for(int i=0;i<n2;i++)
    b[i] = arr[mid+1+i];

    int i=0, j=0, k=l;
    while(i < n1 && j < n2)
    {
        if(a[i] < b[j])
            arr[k++] = a[i++];
        else{
            arr[k++] = b[j++];
            inv+= n1 - i; // very important
        }
    }

    while(i < n1)
    arr[k++] = a[i++];

    while(j < n2)
    arr[k++] = b[j++];

    return inv;
}

long long MergeSort(int arr[], int l, int r)
{
    long long inv = 0;
    //if(l>=r)
    //return 0;
    if(l < r)
    {
        int mid = (l+r)/2;

        inv+= MergeSort(arr,l,mid);
        inv+= MergeSort(arr,mid+1,r);

        inv+= Merge(arr,l,mid,r);
    }
    return inv;
}

int main()
{
    int n;
    cout<<"Enter array size\n";
    cin>>n;
    int arr[n];

    cout<<"Enter elements\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];

    cout<<"Inversions: "<<MergeSort(arr,0,n-1)<<"\n";
    return 0;
}