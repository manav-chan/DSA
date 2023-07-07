#include <queue>
#include <cmath>
int signum(int a, int b)
{
    if(a == b)
        return 0;
    else if(a > b)
        return 1;
    else
        return -1;
}

void call_Median(int element, priority_queue<int> &maxh, priority_queue<int,vector<int>,greater<int>> &minh, int &median)
{
    switch( signum(maxh.size(), minh.size()) )
    {
        case 0:
            if(element > median)
            {
                minh.push(element);
                median = minh.top();
            }
            else
            {
                maxh.push(element);
                median = maxh.top();
            }
            break;
        case 1:
            if(element > median)
            {
                minh.push(element);
                int avg = (maxh.top() + minh.top())/2;
                median = floor(avg);
            }
            else
            {
                minh.push(maxh.top());
                maxh.pop();
                maxh.push(element);
                
                int avg = (maxh.top() + minh.top())/2;
                median = floor(avg);
            }
            break;
        case -1:
            if(element > median)
            {
                maxh.push(minh.top());
                minh.pop();
                minh.push(element);
                
                int avg = (maxh.top() + minh.top())/2;
                median = floor(avg);
            }
            else
            {
                maxh.push(element);
                int avg = (maxh.top() + minh.top())/2;
                median = floor(avg);
            }
            break;
    }
}

vector<int> findMedian(vector<int> &arr, int n){
    vector<int> ans;
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    
    int median = -1;
    for(int i=0; i<n; i++)
    {
        call_Median(arr[i], maxh, minh, median);
        ans.push_back(median);
    }
    return ans;
}
