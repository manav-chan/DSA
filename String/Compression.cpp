#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    string ans="";
    cin>>s;
    for(int i=0;i<s.length();i++)
    {  
        if(s[i] != s[i+1])
        ans+=s[i];
    }
    cout<<ans<<endl;
    return 0;
}