#include <iostream>
#include <stack>
using namespace std;

void deletemid(stack<int> &st, int k)
{
    if(st.empty())
    return;

    if(k==1)
    {
        st.pop();
        return;
    }

    int temp = st.top();
    st.pop();
    deletemid(st,k-1);
    st.push(temp);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    int k = st.size()/2 + 1;
    deletemid(st,k);

    while(!st.empty())
    {
        cout<<st.top()<<"\n";
        st.pop();
    }
    return 0;
}