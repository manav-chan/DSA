#include <iostream>
#include <climits>
using namespace std;

bool isValid(int arr[], int n, int k, int mx)
{
    int students = 1, sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
        if(sum > mx)
        {
            students ++;
            sum = arr[i];

            if(students > k)
            return false;
        }
    }
    return true;
}

int pageAllocation(int arr[], int n, int k) // painters partition same solution
{
    if(k > n)
    return -1;

    int start = INT_MIN; // maximum element in array
    int end = 0; // sum of all elements of array
    for(int i=0; i<n; i++)
    {
        if(arr[i] > start)
        start = arr[i];

        end += arr[i];
    }

    int res = -1;
    while(start <= end)
    {
        int mid = start + (end-start)/2;
        if(isValid(arr,n,k,mid))
        {
            res = mid;
            end = mid-1;
        }
        else
        start = mid+1;
    }
    return res;
}

int main()
{
    int arr[] = {12,34,67,90};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2; // no. of students

    cout<<pageAllocation(arr,n,k)<<"\n";
    return 0;
}