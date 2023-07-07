#include <iostream>
using namespace std;

int catalan(int n) // O(n^2) not practical, in dynamic programming we can do with O(n)
{
    if(n <= 1)
    return 1;

    int res = 0;
    for(int i=0; i <= n-1; i++)
    {
        res += catalan(i) * catalan(n-i-1); 
    }

    return res;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    cout<<catalan(i)<<" ";
    cout<<endl;

    return 0;
}