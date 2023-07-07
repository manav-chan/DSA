#include <iostream>
#include <stack>
using namespace std;

void reverse(string s)
{
    stack<string> st;

    for(int i=0;i<s.length();i++)
    {
        string wd = "";
        while(s[i] != ' ' && i<s.length())
        {
            wd+= s[i];
            i++;
        }
        st.push(wd);
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";
}

int main()
{
    string s = "I like to move it move it.";
    reverse(s);
    return 0;   
}