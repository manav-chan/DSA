#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

int maxArea(vector<int> a)
{
    stack<int> st;
    int area = 0;
    a.push_back(0);
    for(int i=0;i<a.size();i++) // O(n)
    {
        while(!st.empty() && a[st.top()] > a[i])
        {
            int h = a[st.top()];
            st.pop();

            if(st.empty())
            area = max(area, h*i);
            else
            area = max(area, h*(i-st.top()-1));
        }
        st.push(i);
    }

    return area; 
}

int main()
{
    vector<int> a = {5,2,3};
    cout<<maxArea(a)<<"\n";
    return 0;
}