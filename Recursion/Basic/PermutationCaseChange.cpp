#include <iostream>
using namespace std;

void permutationCase(string s, string ans)
{
    if(s == "")
    {
        cout<<ans<<"\n";
        return;
    }

    string ros = s.substr(1);
    permutationCase(ros,ans+s[0]);
    permutationCase(ros,ans+(char)(s[0] - 32));
}

int main()
{
    string s = "abcde";
    permutationCase(s,"");
    return 0;
}