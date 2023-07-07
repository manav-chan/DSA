#include <bits/stdc++.h>

int countSubsetSum(vector<int> &arr, int n, int sum)
{
    int mod = 1e9 + 7;
    int t[n+1][sum+1];
    
    t[0][0] = 1;
    for(int i=1; i<=sum; i++)
        t[0][i] = 0;
    
    
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=sum; j++)
        {
            if(arr[i-1] <= j)
                t[i][j] = (t[i-1][j-arr[i-1]] + t[i-1][j]) % mod;
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}

int countPartitions(int n, int d, vector<int> &arr) 
{
    int sum = 0;
    for(int i=0; i<n; i++)
    sum += arr[i];
    
    if(sum < d || ((sum+d) % 2 == 1)) // s1 needs to be a whole number
        return 0;

    int target = (sum+d)/2;
    return countSubsetSum(arr,n,target);
}