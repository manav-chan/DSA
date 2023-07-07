#include <iostream>
using namespace std;

bool sorted(int arr[], int n)
{
    if(n==1)
    {
        return (arr[1]>arr[0]);
    }
    return (arr[n]>arr[n-1] && sorted(arr,n-1));
}

bool sortedidi(int arr[], int n)
{
    if(n==1)
    {
        return true;
    }
    bool restArray = sortedidi(arr+1, n-1);
    return (arr[0] <arr[1] && restArray);
}

int main()
{
    int n=3;
    int arr[n]={1,1,5,5,4};
    cout<<sorted(arr,n-1)<<endl;
    cout<<sortedidi(arr,n-1)<<endl;
    return 0;
}