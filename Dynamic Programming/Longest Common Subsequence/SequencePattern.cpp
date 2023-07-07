class Solution {
public:
    
    int LCS(string a, string b, int m, int n)
    {
        int t[m+1][n+1];
        for(int i=0; i<=m; i++)
        t[i][0] = 0;

        for(int i=1; i<=n; i++)
        t[0][i] = 0;

        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(a[i-1] == b[j-1])
                t[i][j] = t[i-1][j-1] + 1;
                else
                t[i][j] = max(t[i-1][j] , t[i][j-1]);
            }
        }
        return t[m][n];
    }
    
    bool isSubsequence(string s, string t)
    {
        int lcs = LCS(s, t, s.length(), t.length());
        if(s.length() == lcs)
            return true;
        else
            return false;
    }
};