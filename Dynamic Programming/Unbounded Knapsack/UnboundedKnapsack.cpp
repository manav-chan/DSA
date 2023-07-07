//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        int t[N+1][W+1];
        for(int i=0; i<=N; i++)
        t[i][0] = 0;
        
        for(int i=0; i<=W; i++)
        t[0][i] = 0;
        
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=W; j++)
            {
                if(wt[i-1] <= j)
                t[i][j] = max( (val[i-1] + t[i][j-wt[i-1]]), t[i-1][j] );
                else
                t[i][j] = t[i-1][j];
            }
        }
        return t[N][W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends