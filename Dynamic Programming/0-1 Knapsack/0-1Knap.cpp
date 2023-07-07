//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Top Down Approach
       int t[1001][1001];
       for(int i=0; i<=n; i++)
       t[i][0] = 0;
       for(int i=0; i<=W; i++)
       t[0][i] = 0;
       
       for(int i=1; i<=n; i++)
       {
           for(int j=1; j<=W; j++)
           {
               if(wt[i-1] <= j)
               t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]] , t[i-1][j]);
               else if(wt[i-1] > j)
               t[i][j] = t[i-1][j];
           }
       }
       return t[n][W];
    }

    // Memoization
    int dp[1001][1001];
    // memset(dp,-1,sizeof(dp));
    int knapMemo(int W, int wt[], int val[], int n) 
    {
        if(n == 0 || W == 0)
        return 0;
        
        if(dp[n][W] != -1)
        return dp[n][W];

        if(wt[n-1] <= W)
        return dp[n][W] = max(val[n-1] + knapMemo(W-wt[n-1], wt, val, n-1) , knapMemo(W,wt,val,n-1));

        else if(wt[n-1] > W)
        return dp[n][W] = knapMemo(W,wt,val,n-1);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends