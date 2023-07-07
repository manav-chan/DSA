#include <iostream>
using namespace std;
int fac(int n)
{
    int fact=1;
    for(int i=2;i<=n;++i)
    fact*=i;
    return fact;
}

int binomial(int n, int r)
{
    int res = 1;

    if(r > n-r)
    r = n-r;

    for(int i=0; i<r; i++)
    {
        res*= (n-i);
        res/= (i+1);
    }
    
    return res;
}

int main()
{
    int n,r,b;
    cout<<"Enter n and r\n";
    cin>>n>>r;
    // b=fac(n)/(fac(n-r)*fac(r));
    // cout<<b<<endl;

    cout<<binomial(n,r);
    cout<<endl;
    return 0;
}