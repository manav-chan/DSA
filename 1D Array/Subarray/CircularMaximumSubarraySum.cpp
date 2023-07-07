#include <iostream>
#include <climits>
using namespace std;

int kadane(int arr[], int n)
{
    int sum=0;
    int mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(sum<0)
            sum=0;
        
        sum+=arr[i];
        mx=max(mx,sum);
    }
    return mx;
}

int main()
{
    int n;
    cout<<"Enter array size\n";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements\n";
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    int wrapsum=0;
    int nonwrapsum=0;
    nonwrapsum=kadane(arr,n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        arr[i]=-arr[i];
    }
    wrapsum=kadane(arr,n)+sum;
    cout<<"Maximum Sum Subarray: "<<max(wrapsum, nonwrapsum)<<endl;
    return 0;
}