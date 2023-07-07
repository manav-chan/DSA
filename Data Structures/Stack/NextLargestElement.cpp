#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std; // for nearest greatest to left, we only iterate from left to right and don't reverse answer vector.

vector<int> NextLargestElement(vector<int> a) // aka nearest greatest to right
{
    vector<int> ans;
    stack<int> st;
    for(int i=a.size()-1; i>=0; i--)
    {
        if(st.empty())
        ans.push_back(-1);

        else
        {
            while(!st.empty() && st.top() <= a[i])
            {
                st.pop();
            }
            if(st.empty())
            ans.push_back(-1);

            else                       //if(st.top() > a[i])
            ans.push_back(st.top());
        }
        st.push(a[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    vector<int> a = {1,3,2,4};

    vector<int> ans = NextLargestElement(a);
    for(auto i:ans)
    cout<<i<<" ";
    cout<<"\n";
    return 0;
}