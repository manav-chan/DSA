#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> StockSpan(vector<int> a)
{
    vector<int> ans;
    stack<int> st;
    for(int i=0; i<a.size(); i++)
    {
        if(st.empty())
        ans.push_back(i+1);

        else
        {
            while(!st.empty() && a[st.top()] <= a[i])
            st.pop();

            if(st.empty())
            ans.push_back(i+1);

            else               //if(a[st.top()] > a[i])
            ans.push_back(i-st.top());
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    vector<int> a = {100,80,60,70,60,75,85};

    vector<int> ans = StockSpan(a);
    for(auto i:ans)
    cout<<i<<" ";
    cout<<"\n";
    return 0;
}