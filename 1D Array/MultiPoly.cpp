#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    int p[2*n-1];
    for(int i=0;i<(2*n-1);i++)
    {
        p[i]=0;
    }
    for(int i=0;i<n; i++)
    {
        for(int j=0;j<n; j++)
        {
            p[i+j]= p[i+j] + a[i] * b[j];
        }
    }
    for(int i=0;i<(2*n-1);i++)
    {
        cout<<p[i]<<" ";
    }
}