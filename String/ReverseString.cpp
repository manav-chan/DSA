#include <iostream>
#include <string>
using namespace std;

void reverse(string s,int i)
{
    if(i==s.length())
    return;
    reverse(s,i+1);
    cout<<s[i];

}

void reversedidi(string s)
{
    if(s=="")
    {
        return;
    }
    reversedidi(s.substr(1));
    cout<<s[0];
}

int main()
{
    string s;
    cin>>s;
    reverse(s,0);
    cout<<endl;
    reversedidi(s);
    return 0;
}