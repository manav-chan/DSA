//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
    int LCS(string a, string b, int m, int n)
    {
        int t[m+1][n+1];
        for(int i=0; i<=m; i++)
        t[i][0] = 0;
        
        for(int i=0; i<=n; i++)
        t[0][i] = 0;
        
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(a[i-1] == b[j-1])
                t[i][j] = t[i-1][j-1] + 1;
                else
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
        return t[m][n];
    }
  
    int longestPalinSubseq(string A)
    {
        string B = A;
        reverse(B.begin(), B.end());
        return LCS(A,B,A.length(),B.length());
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends