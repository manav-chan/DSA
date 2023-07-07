#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> f;

void permute(string s, string ans)
{
    if(s == "")
    {
        f.push_back(ans);
        return;
    }

    for(int i=0;i<s.length();i++)
    {
        string ros = s.substr(0,i) + s.substr(i+1);
        permute(ros,ans + s[i]);
    }
}

int main()
{
    string s;
    cout<<"Enter string\n";
    cin>>s;
    string ans = "";

    permute(s,ans);
    
    for(auto elem:f)
    cout<<elem<<endl;

    return 0;
}