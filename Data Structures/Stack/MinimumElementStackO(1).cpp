#include <iostream>
#include <stack>
using namespace std;

stack<int> st;
int minelem = -1;

void push(int val)
{
    if(st.empty())
    {
        st.push(val);
        minelem = val;
    }

    else
    {
        if(val >= minelem)
        st.push(val);

        else if(val < minelem)
        {
            st.push(2*val - minelem);
            minelem = val;
        }
    }
}

void pop()
{
    if(st.empty())
    return;

    else
    {
        if(st.top() >= minelem)
        st.pop();

        else if(st.top() < minelem)
        {
            minelem = 2*minelem - st.top();
            st.pop();
        }
    }
}

int top()
{
    if(st.empty())
    return -1;

    else
    {
        if(st.top() >= minelem)
        return st.top();

        else if(st.top() < minelem)
        return minelem;
    }
}