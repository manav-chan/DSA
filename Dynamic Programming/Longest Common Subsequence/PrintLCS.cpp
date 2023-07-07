#include<iostream>
#include <algorithm>
using namespace std;

void printLCS(string a, string b, int m, int n)
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

    int i = m, j = n;
    string s = "";
    while(i > 0 && j > 0)
    {
        if(a[i-1] == b[j-1])
        {
            s.push_back(a[i-1]);
            i--, j--;
        }
        else
        {
            if(t[i-1][j] > t[i][j-1])
            i--;
            else
            j--;
        }
    }

    reverse(s.begin(), s.end());
    cout<<s<<endl;
}

int main()
{
    string x = "acbcf";
    string y = "abcdaf";
    printLCS(x,y,x.length(),y.length());
    return 0;
}