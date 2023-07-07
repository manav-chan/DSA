#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int l = i*2 + 1, r = i*2 + 2;
    int mx = i;

    if(l < n && arr[l] > arr[mx])
    mx = l;
    if(r < n && arr[r] > arr[mx])
    mx = r;

    if(i != mx)
    {
        swap(arr[i], arr[mx]);
        heapify(arr, n, mx);
    }
}

void buildHeap(int arr[], int n)
{
    for(int i=n/2; i>=0; i--)
    heapify(arr, n, i);
}

void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    while(n > 0)
    {
        swap(arr[0], arr[n-1]);
        n --;
        heapify(arr, n, 0);
    }

}

int main()
{
    int arr[] = {5, 2, 1, 3, 5, 1, 4, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);
    for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}