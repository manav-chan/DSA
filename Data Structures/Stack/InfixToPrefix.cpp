#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int precedence(char ch)
{
    if(ch == '^')
    return 3;

    else if(ch == '*' || ch == '/' || ch == '%')
    return 2;
    
    else if(ch == '+' || ch == '-')
    return 1;

    else
    return -1;
}

string infixToPrefix(string s)
{
    reverse(s.begin(),s.end());
    stack<char> st;
    string ans = "";

    for(int i=0;i<s.length();i++)
    {
        if(s[i] == ')') // reversing condition as string is reversed
        st.push(s[i]);

        else if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
        ans+= s[i];

        else if(s[i] == '(') // reversing condition
        {
            while(!st.empty() && st.top() != ')')
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
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s = "(a-b/c)*(a/k-l)";
    cout<<infixToPrefix(s)<<"\n";
    return 0;
}