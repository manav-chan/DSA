#include <iostream>
#include <stack>
#include <vector>
using namespace std; // for nearest smallest to right, traverse from right to left and reverse answer in the end

vector<int> NearestSmallestElement(vector<int> a) // Nearest smallest element to left
{
    vector<int> ans;
    stack<int> st;
    for(int i=0; i<a.size(); i++)
    {
        if(st.empty())
        ans.push_back(-1);

        else
        {
            while(!st.empty() && st.top() >= a[i])
            st.pop();

            if(st.empty())
            ans.push_back(-1);

            else                      //if(st.top() < a[i])
            ans.push_back(st.top());
        }
        st.push(a[i]);
    }
    return ans;
}

int main()
{
    vector<int> a = {4,5,2,10,8};

    vector<int> ans = NearestSmallestElement(a);
    for(auto i:ans)
    cout<<i<<" ";
    cout<<"\n";
    return 0;
}