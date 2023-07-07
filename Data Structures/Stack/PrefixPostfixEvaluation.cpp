#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int prefixEvaluation(string s) // O(n) length of string
{
    stack<int> st;
    int op1,op2;
    for(int i=s.length()-1; i>=0; i--)
    {
        if(s[i] >= '0' && s[i] <= '9')
        st.push(s[i]-'0');
        else
        {
            op1 = st.top();
            st.pop();
            op2 = st.top();
            st.pop();

            switch (s[i])
            {
                case '+':
                    st.push(op1 + op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '/':
                    st.push(op1 / op2);
                    break;       
                case '%':
                    st.push(op1 % op2);
                    break;
                case '^':
                    st.push(pow(op1,op2));
                    break;         
            }
        }
    }
    return st.top();
}

int postfixEvaluation(string s)
{
    stack<int> st;
    int op1,op2;
    for(int i=0; i<s.length(); i++) // differes here
    {
        if(s[i] >= '0' && s[i] <= '9')
        st.push(s[i]-'0');
        else
        {
            op2 = st.top(); // differs here
            st.pop();
            op1 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;       
            case '%':
                st.push(op1 % op2);
                break;
            case '^':
                st.push(pow(op1,op2));
                break;         
            }
        }
    }
    return st.top();
}

int main()
{
    string s1 = "-+7*45+20";
    string s2 = "46+2/5*7+";
    string s3 = "145+2++3-68++";
    cout<<prefixEvaluation(s1)<<"\n";
    cout<<postfixEvaluation(s3)<<"\n";

    return 0;
}