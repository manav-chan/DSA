#include <iostream>
using namespace std;

int firstOne(int arr[], int n)
{
    int start = 0, end = 1;
    while(arr[end] != 1)
    {
        start = end;
        end *= 2;
    }

    int res = -1;
    while(start <= end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid] == 1)
        {
            res = mid;
            end = mid-1;
        }
        else if(arr[mid] < 1) // == 0
        start = mid+1;
    }
    return res;
}

int main()
{
    int arr[] = {0,0,0,0,0,0,1,1,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout<<firstOne(arr,n)<<"\n";
    return 0;
}