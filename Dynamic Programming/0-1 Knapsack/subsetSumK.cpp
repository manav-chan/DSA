#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    bool dp[1001][1001];
    for(int i=0; i<=n; i++)
        dp[i][0] = true;
    for(int i=1; i<=k; i++)
        dp[0][i] = false;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=k; j++)
        {
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][k];
}