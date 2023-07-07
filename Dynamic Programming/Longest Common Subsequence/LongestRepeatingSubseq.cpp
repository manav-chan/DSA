//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	
        int modLCS(string a, string b, int n)
        {
            int t[n+1][n+1];
            for(int i=0; i<=n ;i++)
            {
                t[i][0] = 0;
                t[0][i] = 0;
            }
            
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(a[i-1] == b[j-1] && i != j)
                    t[i][j] = t[i-1][j-1] + 1;
                    else
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
            return t[n][n];
        }

		int LongestRepeatingSubsequence(string str)
		{
		    string str2 = str;
		    return modLCS(str, str2, str.length());
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends