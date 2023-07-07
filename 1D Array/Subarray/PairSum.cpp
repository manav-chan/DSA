#include <iostream>
#include <climits>
using namespace std;

int PairSum(int arr[], int n, int k)
{
    int low=0, high=n-1;
    while(low<high)
    {
        if(arr[low]+arr[high]==k){
            cout<<low+1<<" "<<high+1<<endl;
            return 1;
        }
        else if(arr[low]+arr[high]<k){
            low++;
        }
        else{
            high--;
        }
    }
    cout<<"Pair does not exist\n";
    return 0;
}

int main()
{
    int n,k;
    cout<<"Enter array size\n";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements\n";
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    cout<<"Enter sum\n";
    cin>>k;
    PairSum(arr,n,k);
    return 0;
}