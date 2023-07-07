#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n;
    int mx=INT_MIN;
    cout<<"Enter array size\n";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements\n";
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(sum<0)
        sum=0;
        sum+= arr[i];
        mx=max(mx, sum);
    }
    cout<<"Maximum Sum Subarray: "<<mx<<endl;
    return 0;
}