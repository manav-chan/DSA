#include <iostream>
using namespace std;

void heapify(int arr[], int n, int idx)
{
    int largest = idx;
    int left = 2 * idx;
    int right = (2*idx) + 1;

    if(left <= n && arr[left] > arr[largest])
    largest = left;
    if(right <= n && arr[right] > arr[largest])
    largest = right;

    if(idx != largest)
    {
        swap(arr[idx], arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapsort(int arr[], int n)
{
    int size = n;
    while(size > 1)
    {
        swap(arr[1], arr[size]);
        size --;

        heapify(arr,size,1);
    }
}

int main()
{
    int arr[] = {-1,3,5,6,4,1,2};
    int n = sizeof(arr)/sizeof(arr[0]) - 1;

    //building heap
    for(int i=n/2; i>0; i--)
    heapify(arr,n,i);

    //sorting
    heapsort(arr,n);

    for(int i=1;i<=n;i++)
    cout<<arr[i]<<" ";

    cout<<endl;

    return 0;
}