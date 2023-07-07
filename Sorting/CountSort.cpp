#include <iostream>
using namespace std;

void CountSort(int arr[], int n)
{
    int maxe = arr[0]; // maximum element of array maxe
    for(int i=0;i<n;i++)
    maxe = max(arr[i],maxe);

    int count[maxe+1] = {0}; // it works but usually dynamic array allocation not allowed use new
    for(int i=0;i<n;i++)
    count[arr[i]]++;

    int ans[n] = {0}; // my method
    int k = 0;
    for(int i=0;i<=maxe;i++)
    {
        while(count[i] != 0)
        {
            ans[k++] = i;
            --count[i];
        }
    }

    /*for(int i=1;i<=maxe;i++) // course method
    { 
        count[i]+= count[i-1]; 
    }

    int ans[n] = {0};
    for(int i=n-1;i>=0;i--)
    {
        ans[--count[arr[i]]] = arr[i];
    }
    */
    for(int i=0;i<n;i++)
    arr[i] = ans[i];
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

    CountSort(arr,n);
    cout<<"Sorted Array\n";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

    return 0;
}