#include <iostream>
#include <queue>
using namespace std;

int connectRopes(int arr[], int n)
{
    int sum = 0;
    priority_queue<int,vector<int>,greater<int>> minh;

    for(int i=0;i<n;i++)
    minh.push(arr[i]);

    while(minh.size() >= 2)
    {
        int a = minh.top();
        minh.pop();
        int b = minh.top();
        minh.pop();

        sum += a + b;
        minh.push(a+b);
    }

    return sum;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<connectRopes(arr,n)<<endl;
    return 0;
}