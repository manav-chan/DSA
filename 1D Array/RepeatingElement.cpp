#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n;
    int mini=INT_MAX;
    const int N=10;
    int hash[N];
    cout<<"Enter array size\n";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements\n";
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    for(int i=0;i<N;i++)
    {
        hash[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        if(hash[arr[i]] != -1)
        mini=min(mini,hash[arr[i]]);
        else
        hash[arr[i]]=i;
    }
    if(mini==INT_MAX)
    cout<<"No repeating element\n";
    else
    cout<<"Index of repeating: "<<mini+1<<endl;
    return 0;
}