#include <iostream>
#include <climits>
using namespace std;

int maxSum(int arr[], int n, int k)
{
    int i = 0, j = 0;
    int sum = 0;
    int mxsum = INT_MIN;

    while(j < n)
    {
        sum += arr[j];
        
        if(j-i+1 < k)
        j++;

        else if(j-i+1 == k)
        {
            mxsum = max(mxsum, sum);
            sum -= arr[i];
            i++, j++;
        }
    }
    return mxsum;
}

int main()
{
    int arr[] = {2,5,1,8,2,9,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    cout<<maxSum(arr,n,k)<<"\n";
    return 0;
}