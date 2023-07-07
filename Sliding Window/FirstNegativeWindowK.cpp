#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> firstNegative(int arr[], int n, int k)
{
    int i = 0, j = 0;
    queue<int> q;
    vector<int> ans;

    while(j < n)
    {
        if(arr[j] < 0)
        q.push(arr[j]);

        if(j-i+1 < k)
        j++;

        else if(j-i+1 == k)
        {
            if(q.empty())
            ans.push_back(0);
            else
            ans.push_back(q.front());

            if(arr[i] == q.front())
            q.pop();

            i++, j++;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {12,-1,-7,8,-15,30,16,28};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    vector<int> ans = firstNegative(arr,n,k);
    for(auto element:ans)
    cout<<element<<" ";

    cout<<endl;
    return 0;
}