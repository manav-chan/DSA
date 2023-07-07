#include <iostream>
#include <stack>
using namespace std;

void insert(stack<int> &st, int val)
{
    if(st.empty() || (!st.empty() && st.top() <= val))
    {
        st.push(val);
        return;
    }

    int temp = st.top();
    st.pop();
    insert(st,val);
    st.push(temp);
}

void sort(stack<int> &st)
{
    if(st.empty())
    return;

    int temp = st.top();
    st.pop();
    sort(st);
    insert(st,temp);
}

int main()
{
    stack<int> st;
    st.push(5);
    st.push(1);
    st.push(0);
    st.push(2);

    sort(st);
    cout<<st.top()<<"\n";
    st.pop();
    cout<<st.top()<<"\n";
    st.pop();
    cout<<st.top()<<"\n";
    st.pop();
    cout<<st.top()<<"\n";
    st.pop();

    return 0;
}