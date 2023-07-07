#include <iostream>
#include <vector>
using namespace std;

int longestSubstr(string s)
{
    vector<int> dict(256,-1);
    int start = -1, maxlen = 0;
    for(int i=0;i<s.length();i++)
    {
        if(dict[s[i]] > start)
        start = dict[s[i]];

        dict[s[i]] = i;
        maxlen = max(maxlen,i-start);
    }
    return maxlen;
}

int main()
{
    string s = "pwwkew";
    cout<<longestSubstr(s)<<"\n";
    return 0;
}