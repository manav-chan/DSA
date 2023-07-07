#include <iostream>
#include <stack>
using namespace std;

int precedence(char c)
{
    if(c == '^')
    return 3;

    else if(c == '*' || c == '/' || c == '%')
    return 2;

    else if(c == '+' || c == '-')
    return 1;

    else // condition for if we bracket for checking precedence.
    return -1;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string ans = "";
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '(')
        st.push(s[i]);

        else if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || s[i] >= '0' && s[i] <= '9')
        ans+= s[i];

        else if(s[i] == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                ans+= st.top();
                st.pop();
            }
            if(!st.empty())
            st.pop();
        }

        else
        {
            while(!st.empty() && precedence(s[i]) <= precedence(st.top()))
            {
                ans+= st.top();
                st.pop();
            }
            st.push(s[i]); 
        }
    }

    while(!st.empty())
    {
        ans+= st.top();
        st.pop();
    }

    return ans;
}

int main()
{
    // string s = "(a-b/c)*(a/k-l)";
    string s = "(1+(4+5+2)-3)+(6+8)";
    cout<<infixToPostfix(s)<<"\n";
    return 0;
}