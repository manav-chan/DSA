#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int MCM(vector<int> &arr, int i, int j)
{
    if(i >= j)
    return 0;

    int minCost = INT_MAX;
    for(int k = i; k < j; k ++) {
        int temp = MCM(arr, i, k) + MCM(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];
        minCost = min(minCost, temp);
    }
    return minCost;
}

int main()
{
    int N;
    cin>>N;

    vector<int> arr(N);
    for(auto &i: arr)
    cin>>i;

    int cost = MCM(arr, 1, N-1);
    cout<<cost<<endl;
    return 0;
}