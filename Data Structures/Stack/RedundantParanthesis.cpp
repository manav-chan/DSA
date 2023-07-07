#include <iostream>
#include <stack>
using namespace std;

bool redundantBraces(string s)
{
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '(')
        st.push(s[i]);

        else if(s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='*')
        st.push(s[i]);

        else if(s[i] == ')')
        {
            if(st.top() == '(')
            return true;

            while(!st.empty() && st.top() != '(')
            st.pop();

            st.pop();
        }
    }
    return false;
}

int main()
{
    cout<<redundantBraces("(a+(b+c))");
    return 0;
}