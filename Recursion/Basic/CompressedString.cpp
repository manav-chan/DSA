#include <iostream>
#include <string>
using namespace std;

string compress(string s)
{
    if(s == "")
    return "";
    if(s[0] != s[1])
    cout<<s[0];
    return compress(s.substr(1));
}

string compressdidi(string s)
{
    if(s == "")
    return "";
    
    char ch = s[0];
    string ans = compressdidi(s.substr(1));

    if(ch == ans[0])
    return ans;
    
    return (ch+ans);
}

int main()
{
    string s;
    cout<<"Enter string\n";
    cin>>s;
    compress(s);
    cout<<"\n"<<compressdidi(s)<<"\n";
}