#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> NSL(vector<int> a)
{
    stack<int> st;
    vector<int> left;
    for(int i=0; i<a.size(); i++)
    {
        if(st.empty())
        left.push_back(-1); // we add boundary

        else
        {
            while(!st.empty() && a[st.top()] >= a[i])
            st.pop();

            if(st.empty())
            left.push_back(-1);

            else
            left.push_back(st.top());
        }
        st.push(i);
    }
    return left;
}

vector<int> NSR(vector<int> a)
{
    vector<int> right;
    stack<int> st;
    for(int i=a.size()-1; i>=0; i--)
    {
        if(st.empty())
        right.push_back(a.size()); // we add boundary

        else
        {
            while(!st.empty() && a[st.top()] >= a[i])
            st.pop();

            if(st.empty())
            right.push_back(a.size());

            else
            right.push_back(st.top());
        }
        st.push(i);
    }
    reverse(right.begin(),right.end());
    return right;
}

int MaxAreaHistogram(vector<int> a)
{
    vector<int> left = NSL(a);
    vector<int> right= NSR(a);
    vector<int> area;
    
    int temparea;
    for(int i=0;i<a.size();i++)
    {
        temparea = (right[i] - left[i] - 1) * a[i]; // length * height
        area.push_back(temparea);
    }
    int maxarea = area[0];
    for(int i=1;i<area.size();i++)
    {
        maxarea = max(maxarea,area[i]);
    }
    
    return maxarea;
}

int maxAreaMatrix(vector<vector<int>> a, int m, int n)
{
    vector<int> v;
    for(int j=0;j<n;j++)
    v.push_back(a[0][j]);

    int mx = MaxAreaHistogram(v);
    for(int i=1;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j] == 0)
            v[j] = 0;

            else
            v[j] = v[j] + a[i][j]; // v[j] = v[j] + 1;
        }
        mx = max(mx,MaxAreaHistogram(v));
    }
    return mx;
}
int main()
{
    int m,n;
    m = n = 4;
    vector<vector<int>> arr = { {0,1,1,0},
                                {1,1,1,1},
                                {1,1,1,1},
                                {1,1,0,0} };
    cout<<maxAreaMatrix(arr,m,n)<<"\n";
    return 0;
}