#include <iostream>
using namespace std;

int firstocc(int arr[], int n, int i, int key)
{
    if(i==n)
    {
        return -1;
    }
    if(arr[i]==key)
    {
        return i;
    }
    return firstocc(arr,n,i+1,key);
}

int lastocc(int arr[], int n, int i, int key)
{
    if(i==n)
    {
        return -1;
    }
    int t=lastocc(arr,n,i+1,key);
    if(t != -1)
    {
        return t;
    }
    if(arr[i]==key)
    {
        return i;
    }
    return -1;
}

int main()
{
    int n,a;
    n=7;
    int arr[n]={4,2,1,2,5,2,7};
    cout<<firstocc(arr,n,0,2)<<endl;
    cout<<lastocc(arr,n,0,2)<<endl;
    return 0;
}