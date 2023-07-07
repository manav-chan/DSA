//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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
	            t[i][j] = max(t[i][j-1] , t[i-1][j]);
	        }
	    }
	    return t[m][n];
	}
	
	int minOperations(string str1, string str2) 
	{ 
	    int lcs = LCS(str1,str2,str1.length(),str2.length());
	    int del = str1.length() - lcs;
	    int ins = str2.length() - lcs;
	    
	    return del + ins;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends