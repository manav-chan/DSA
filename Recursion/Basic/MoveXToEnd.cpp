#include <iostream>
#include <string>
using namespace std;

string movex(string s)
{
    if(s.length() == 0)
    return "";

    string ans = movex(s.substr(1));

    if(s[0] == 'x')
    return ans + s[0];

    return s[0] + ans;
}

int main()
{
    string s;
    cout<<"Enter string\n";
    cin>>s;
    cout<<movex(s)<<"\n";
    return 0;
}