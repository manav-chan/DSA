#include <iostream>
using namespace std;
int main()
{
    int n;
    int mx=0;
    int a=0;
    cout<<"Enter array size\n";
    cin>>n;
    int arr[n+1];
    arr[n]=-1;
    cout<<"Enter array elements\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>mx && arr[i]>arr[i+1])
        a++;
        mx=max(arr[i],mx);
    }
    cout<<"Record Breaking: "<<a<<endl;
    return 0;
}