#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void count_sort(int arr[], int n, int expo)
{
    int count[10] = {0};

    for(int i=0; i<n; i++)
        count[(arr[i] / expo) % 10] ++;

    for(int i=1; i<n; i++)
        count[i] += count[i-1];

    int sorted[n];
    for(int i=n-1; i>=0; i--)
    {
        sorted[-- count[(arr[i] / expo) % 10]] = arr[i];
    }

    for(int i=0; i<n; i++)
    arr[i] = sorted[i];
}

void radix_sort(int arr[], int n)
{
    int maximum = INT_MIN;
    for(int i=0; i<n; i++)
    maximum = max(maximum, arr[i]);

    for(int i=1; maximum / i > 0; i *= 10)
    {
        count_sort(arr, n, i);
    }

    for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr[] = {15, 1, 321, 10, 802, 2, 123, 90, 109, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    radix_sort(arr, n);
    return 0;
}