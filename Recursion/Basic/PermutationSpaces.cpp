#include <iostream>
using namespace std;

void permutationSpaces(string s, string ans)
{
    if(s == "")
    {
        cout<<ans<<"\n";
        return;
    }

    string ros = s.substr(1);
    permutationSpaces(ros,ans+s[0]);
    permutationSpaces(ros,ans+" "+s[0]);
}

int main()
{
    string s = "ABCDE";

    string ans = "";
    ans+= s[0];
    s = s.substr(1);
    permutationSpaces(s,ans);
    return 0;
}