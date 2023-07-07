#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    int sum=0;
    cout<<"Enter array size\n";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements\n";
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;++i)
    {
        for(int j=i;j<n;++j)
        {
            sum=sum+arr[j];
            cout<<sum<<endl;
        }
    }
    return 0;
}