#include <iostream>
using namespace std;
int main()
{
    int n,s,sum=0,st=0;
    cout<<"Enter array size\n";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter sum\n";
    cin>>s;
    for(int j=0;j<n;j++)
    {
        sum+=arr[j];
        while(sum>s && st<j)
        {
            sum-=arr[st];
            st++;
        }
        if(sum==s)
        {
            cout<<"Sum found between: "<<st+1<<" "<<j+1<<endl;
            return 1;
        }
    }
    cout<<"Sum not found\n";
    return 0;
}