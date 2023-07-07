#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int RainWater(int a[], int n)
{
    int maxL[n], maxR[n];
    maxL[0] = a[0];
    maxR[n-1] = a[n-1];

    for(int i=1;i<n;i++)
    {
        maxL[i] = max(maxL[i-1], a[i]);
    }
    for(int i=n-2;i>=0;i--)
    {
        maxR[i] = max(maxR[i+1], a[i]);
    }

    int water = 0;
    for(int i=0;i<n;i++)
    {
        water+= min(maxL[i],maxR[i]) - a[i];
    }
    return water;
}

int RainWaterStack(int a[], int n)
{
    stack<int> st;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && a[st.top()] < a[i])
        {
            int val = st.top();
            st.pop();

            if(st.empty())
            break;

            int diff = i - st.top() - 1;
            ans+= (min(a[i], a[st.top()]) - a[val]) * diff;
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    int a[] = {0,1,0,2,1,0,1,3,2,1,2};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<RainWater(a,n)<<"\n";
    cout<<RainWaterStack(a,n)<<"\n";
    return 0;
}