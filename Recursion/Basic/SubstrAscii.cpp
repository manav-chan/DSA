#include <iostream>
#include <string>
using namespace std;

void substrascii(string s, string ans)
{
    if(s.length() == 0)
    {
        cout<<ans<<"\n";
        return;
    }
    string ros = s.substr(1);
    int code = s[0];

    substrascii(ros,ans);
    substrascii(ros,ans+s[0]);
    substrascii(ros,ans+to_string(code));
}

int main()
{
    string s;
    cout<<"Enter string\n";
    cin>>s;
    substrascii(s,"");
    return 0;
}