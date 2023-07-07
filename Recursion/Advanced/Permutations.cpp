#include <iostream>
using namespace std;

void Permutations(string s, string ans) // O(n*2^n)
{ 
    if(s.length() == 0)
    {
        cout<<ans<<"\n";
        return;
    }

    for(int i=0;i<s.length();i++)
    {
        string ros = s.substr(0,i) + s.substr(i+1);
        Permutations(ros,ans+s[i]);
    }
}

int main()
{
    string s;
    cout<<"Enter string\n";
    cin>>s;
    Permutations(s,"");
    return 0;
}