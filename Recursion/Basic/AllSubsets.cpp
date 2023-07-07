#include <iostream>
#include <string>
using namespace std;

void substrings(string s, string ans)
{
    if(s.length() == 0)
    {
        cout<<ans<<"\n";
        return;
    }

    string ros = s.substr(1);

    substrings(ros, ans);
    substrings(ros, ans+s[0]);
}

int main()
{
    string s;
    cout<<"Enter string\n";
    cin>>s;
    substrings(s,"");
    return 0;
}
/* if want to store unique elements store answers in vector, put those in a set to get sorted non repeating order then print */