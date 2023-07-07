//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

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
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
        return t[m][n];
    }

    int findMinInsertions(string S){
        
        string b = S;
        int m = S.size();
        reverse(b.begin(), b.end());
        
        int lcs = LCS(S, b, m, b.size());
        return m - lcs;
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends