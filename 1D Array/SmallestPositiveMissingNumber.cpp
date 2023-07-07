#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter array size\n";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bool hash[20];
    for(int i=0;i<20;i++)
    {
        hash[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=0)
        hash[arr[i]]=1;
    }
    for(int i=0;i<20;i++)
    {
        if(hash[i]==0)
        {
            cout<<"Missing Number: "<<i<<endl;
            return 1;
        }
    }
    cout<<"Invalid array\n";
    return 0;
}