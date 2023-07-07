#include <iostream>
#include <stack>
using namespace std;

bool checkBalanced(string s)
{
    stack<char> st;

    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(' || s[i]=='[' || s[i]=='{')
        st.push(s[i]);

        else if(s[i]==')')
        {
            if(st.top()=='(')
            st.pop();
            else
            return false;
        }

        else if(s[i]==']')
        {
            if(st.top()=='[')
            st.pop();
            else
            return false;
        }

        else if(s[i]=='}')
        {
            if(st.top()=='{')
            st.pop();
            else
            return false;
        }

        else
        return false;
    }

    if(st.empty())
    return true;

    else 
    return false;
}

int main()
{
    string s = "{[()]}";
    if(checkBalanced(s))
    cout<<"Balanced\n";
    else
    cout<<"Unbalanced\n";

    return 0;
}