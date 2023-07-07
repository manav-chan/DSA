#include <iostream>
#include <string>
using namespace std;

string keypadarr[] = {"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void keypad(string s, string ans)
{
    if(s.length() == 0)
    {
        cout<<ans<<"\n";
        return;
    }
    string code = keypadarr[s[0]-'0'];
    string ros = s.substr(1);

    for(int i=0;i<code.length();i++)
    keypad(ros,ans+code[i]);
}

int main()
{   
    string s;
    cout<<"Enter numbers\n";
    cin>>s;
    keypad(s,"");
    return 0;
}