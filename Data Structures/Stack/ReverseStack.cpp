#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int val)
{
    if(st.empty())
    {
        st.push(val);
        return;
    }

    int topval = st.top();
    st.pop();
    insertAtBottom(st,val);

    st.push(topval);
}

void reverse(stack<int> &st)
{
    if(st.empty())
    return;

    int val = st.top();
    st.pop();
    reverse(st);

    insertAtBottom(st,val);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    reverse(st);

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";

    return 0;
}